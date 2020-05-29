/* SPDX-License-Identifier: GPL-2.0-only */

#include <southbridge/intel/lynxpoint/nvs.h>

void acpi_create_gnvs(global_nvs_t *gnvs)
{
	gnvs->tcrt = 100;
	gnvs->tpsv = 90;
}
