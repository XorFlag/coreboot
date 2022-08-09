/* SPDX-License-Identifier: GPL-2.0-only */

#include <security/vboot/antirollback.h>
#include <program_loading.h>
#include <vb2_api.h>
#include <security/tpm/tss.h>
#include <security/vboot/misc.h>
#include <security/vboot/mrc_cache_hash_tpm.h>
#include <console/console.h>
#include <string.h>

void mrc_cache_update_hash(uint32_t index, const uint8_t *data, size_t size)
{
	struct vb2_hash hash;

	/* Initialize TPM driver. */
	if (tlcl_lib_init() != VB2_SUCCESS) {
		printk(BIOS_ERR, "MRC: TPM driver initialization failed.\n");
		return;
	}

	/* Calculate hash of data generated by MRC. */
	if (vb2_hash_calculate(vboot_hwcrypto_allowed(), data, size,
			       VB2_HASH_SHA256, &hash)) {
		printk(BIOS_ERR, "MRC: SHA-256 calculation failed for data. "
		       "Not updating TPM hash space.\n");
		/*
		 * Since data is being updated in mrc cache, the hash
		 * currently stored in TPM hash space is no longer
		 * valid. If we are not able to calculate hash of the
		 * data being updated, reset all the bits in TPM hash
		 * space to zero to invalidate it.
		 */
		memset(hash.raw, 0, VB2_SHA256_DIGEST_SIZE);
	}

	/* Write hash of data to TPM space. */
	if (antirollback_write_space_mrc_hash(index, hash.sha256, sizeof(hash.sha256))
	    != TPM_SUCCESS) {
		printk(BIOS_ERR, "MRC: Could not save hash to TPM.\n");
		return;
	}

	printk(BIOS_INFO, "MRC: TPM MRC hash idx 0x%x updated successfully.\n", index);
}

int mrc_cache_verify_hash(uint32_t index, const uint8_t *data, size_t size)
{
	struct vb2_hash tpm_hash = { .algo = VB2_HASH_SHA256 };

	/* Initialize TPM driver. */
	if (tlcl_lib_init() != VB2_SUCCESS) {
		printk(BIOS_ERR, "MRC: TPM driver initialization failed.\n");
		return 0;
	}

	/* Read hash of MRC data saved in TPM. */
	if (antirollback_read_space_mrc_hash(index, tpm_hash.sha256, sizeof(tpm_hash.sha256))
	    != TPM_SUCCESS) {
		printk(BIOS_ERR, "MRC: Could not read hash from TPM.\n");
		return 0;
	}

	/* Calculate hash of data read from MRC_CACHE and compare. */
	if (vb2_hash_verify(vboot_hwcrypto_allowed(), data, size, &tpm_hash)) {
		printk(BIOS_ERR, "MRC: Hash comparison failed.\n");
		return 0;
	}

	printk(BIOS_INFO, "MRC: Hash idx 0x%x comparison successful.\n", index);

	return 1;
}
