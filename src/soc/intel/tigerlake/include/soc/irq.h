/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2020 Intel Corporation.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _SOC_IRQ_H_
#define _SOC_IRQ_H_

#if CONFIG(SOC_INTEL_TIGERLAKE)
	#include "irq_tgl.h"
#else
	#include "irq_jsl.h"
#endif /* CONFIG_SOC_INTEL_TIGERLAKE */

#endif /* _SOC_IRQ_H_ */
