/* SPDX-License-Identifier: GPL-2.0-only */

#include <console/console.h>
#include <device/device.h>
#include <cbmem.h>
#include <halt.h>
#include <edid.h>
#include <device/mmio.h>
#include <ramdetect.h>
#include <symbols.h>

static void init_gfx(void)
{
	uint32_t *pl111;
	struct edid edid;
	/* width is at most 4096 */
	/* height is at most 1024 */
	int width = 800, height = 600;
	uint32_t framebuffer = 0x4c000000;
	pl111 = (uint32_t *) 0x10020000;
	write32(pl111, (width / 4) - 4);
	write32(pl111 + 1, height - 1);
	/* registers 2, 3 and 5 are ignored by qemu. Set them correctly if
	   we ever go for real hw.  */
	/* framebuffer address offset. Has to be in vram.  */
	write32(pl111 + 4, framebuffer);
	write32(pl111 + 7, 0);
	write32(pl111 + 10, 0xff);
	write32(pl111 + 6, (5 << 1) | 0x801);

	edid.framebuffer_bits_per_pixel = 32;
	edid.bytes_per_line = width * 4;
	edid.x_resolution = width;
	edid.y_resolution = height;

	set_vbe_mode_info_valid(&edid, framebuffer);
}

static void mainboard_enable(struct device *dev)
{
	int discovered;
	if (!dev) {
		printk(BIOS_EMERG, "No dev0; die\n");
		halt();
	}

	discovered = probe_ramsize((uintptr_t)_dram, CONFIG_DRAM_SIZE_MB);
	printk(BIOS_DEBUG, "%d MiB of RAM discovered\n", discovered);
	ram_resource(dev, 0, 0x60000000 >> 10, discovered << 10);
	cbmem_recovery(0);
	init_gfx();
}

struct chip_operations mainboard_ops = {
	.enable_dev = mainboard_enable,
};
