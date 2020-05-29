/* SPDX-License-Identifier: GPL-2.0-only */

#include <console/console.h>
#include <device/device.h>
#include <device/pci.h>
#include <device/pci_def.h>
#include <device/pci_ops.h>
#include <device/pciexp.h>
#include <device/pci_ids.h>
#include <southbridge/intel/common/pciehp.h>
#include "chip.h"

static void pci_init(struct device *dev)
{
	u16 reg16;
	u32 reg32;
	struct southbridge_intel_i82801jx_config *config = dev->chip_info;

	printk(BIOS_DEBUG, "Initializing ICH10 PCIe root port.\n");

	/* Enable Bus Master */
	pci_or_config16(dev, PCI_COMMAND, PCI_COMMAND_MASTER);

	/* Set Cache Line Size to 0x10 */
	// This has no effect but the OS might expect it
	pci_write_config8(dev, 0x0c, 0x10);

	reg16 = pci_read_config16(dev, PCI_BRIDGE_CONTROL);
	reg16 &= ~PCI_BRIDGE_CTL_PARITY;
	reg16 |= PCI_BRIDGE_CTL_NO_ISA;
	pci_write_config16(dev, PCI_BRIDGE_CONTROL, reg16);

	/* Enable IO xAPIC on this PCIe port */
	reg32 = pci_read_config32(dev, 0xd8);
	reg32 |= (1 << 7);
	pci_write_config32(dev, 0xd8, reg32);

	/* Enable Backbone Clock Gating */
	reg32 = pci_read_config32(dev, 0xe1);
	reg32 |= (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0);
	pci_write_config32(dev, 0xe1, reg32);

	/* Set VC0 transaction class */
	reg32 = pci_read_config32(dev, 0x114);
	reg32 &= 0xffffff00;
	reg32 |= 1;
	pci_write_config32(dev, 0x114, reg32);

	/* Mask completion timeouts */
	reg32 = pci_read_config32(dev, 0x148);
	reg32 |= (1 << 14);
	pci_write_config32(dev, 0x148, reg32);

	/* Lock R/WO Correctable Error Mask. */
	pci_write_config32(dev, 0x154, pci_read_config32(dev, 0x154));

	/* Clear errors in status registers */
	reg16 = pci_read_config16(dev, 0x06);
	pci_write_config16(dev, 0x06, reg16);
	reg16 = pci_read_config16(dev, 0x1e);
	pci_write_config16(dev, 0x1e, reg16);

	/* Get configured ASPM state */
	const enum aspm_type apmc = pci_read_config32(dev, 0x50) & 3;

	/* If both L0s and L1 enabled then set root port 0xE8[1]=1 */
	if (apmc == PCIE_ASPM_BOTH) {
		reg32 = pci_read_config32(dev, 0xe8);
		reg32 |= (1 << 1);
		pci_write_config32(dev, 0xe8, reg32);
	}

	/* Enable expresscard hotplug events.  */
	if (config->pcie_hotplug_map[PCI_FUNC(dev->path.pci.devfn)]) {
		pci_write_config32(dev, 0xd8,
				   pci_read_config32(dev, 0xd8)
				   | (1 << 30));
		pci_write_config16(dev, 0x42, 0x142);
	}
}

static void pch_pciexp_scan_bridge(struct device *dev)
{
	struct southbridge_intel_i82801jx_config *config = dev->chip_info;

	/* Normal PCIe Scan */
	pciexp_scan_bridge(dev);

	if (config->pcie_hotplug_map[PCI_FUNC(dev->path.pci.devfn)]) {
		intel_acpi_pcie_hotplug_scan_slot(dev->link_list);
	}
}

static struct pci_operations pci_ops = {
	.set_subsystem = pci_dev_set_subsystem,
};

static struct device_operations device_ops = {
	.read_resources		= pci_bus_read_resources,
	.set_resources		= pci_dev_set_resources,
	.enable_resources	= pci_bus_enable_resources,
	.init			= pci_init,
	.scan_bus		= pch_pciexp_scan_bridge,
	.ops_pci		= &pci_ops,
};

/* 82801lJx, ICH10  */
static const unsigned short pci_device_ids[] = {
	0x3a40, /* Port 1 */
	0x3a42, /* Port 2 */
	0x3a44, /* Port 3 */
	0x3a46, /* Port 4 */
	0x3a48, /* Port 5 */
	0x3a4a, /* Port 6 */

	0x3a70, /* Port 1 */
	0x3a72, /* Port 2 */
	0x3a74, /* Port 3 */
	0x3a76, /* Port 4 */
	0x3a78, /* Port 5 */
	0x3a7a, /* Port 6 */
	0
};

static const struct pci_driver ich10_pcie __pci_driver = {
	.ops		= &device_ops,
	.vendor		= PCI_VENDOR_ID_INTEL,
	.devices	= pci_device_ids,
};
