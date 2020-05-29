/* SPDX-License-Identifier: GPL-2.0-only */

#include <baseboard/variants.h>
#include <console/console.h>
#include <nhlt.h>
#include <soc/nhlt.h>

void __weak variant_nhlt_init(struct nhlt *nhlt)
{
	/* 1-dmic configuration */
	if (CONFIG(NHLT_DMIC_1CH_16B) &&
		!nhlt_soc_add_dmic_array(nhlt, 1))
		printk(BIOS_ERR, "Added 1CH DMIC array.\n");
	/* 2-dmic configuration */
	if (CONFIG(NHLT_DMIC_2CH_16B) &&
		!nhlt_soc_add_dmic_array(nhlt, 2))
		printk(BIOS_ERR, "Added 2CH DMIC array.\n");
	/* 4-dmic configuration */
	if (CONFIG(NHLT_DMIC_4CH_16B) &&
		!nhlt_soc_add_dmic_array(nhlt, 4))
		printk(BIOS_ERR, "Added 4CH DMIC array.\n");

	if (CONFIG(INCLUDE_SND_MAX98357_DA7219_NHLT)) {
		/* Dialog for Headset codec.
		 * Headset codec is bi-directional but uses the same
		 * configuration settings for render and capture endpoints.
		 */
		if (!nhlt_soc_add_da7219(nhlt, AUDIO_LINK_SSP2))
			printk(BIOS_ERR, "Added Dialog_7219 codec.\n");

		/* MAXIM Smart Amps for left and right speakers. */
		if (!nhlt_soc_add_max98357(nhlt, AUDIO_LINK_SSP1))
			printk(BIOS_ERR, "Added Maxim_98357 codec.\n");
	}

	if (CONFIG(INCLUDE_SND_MAX98373_NHLT) &&
		!nhlt_soc_add_max98373(nhlt, AUDIO_LINK_SSP1))
		printk(BIOS_ERR, "Added Maxim_98373 codec.\n");
}
