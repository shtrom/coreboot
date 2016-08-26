/* intelmetool
 *
 * Copyright (C) 2013-2016 Philipp Deppenwiese <zaolin@das-labor.org>, Alexander Couzens <lynxis@fe80.eu>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include <inttypes.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdio.h>

#define MSR_BOOTGUARD 0x13A

#define BOOTGUARD_DISABLED 0x400000000
#define BOOTGUARD_ENABLED_VERIFIED_MODE 0x100000000
#define BOOTGUARD_ENABLED_MEASUREMENT_MODE 0x200000000
#define BOOTGUARD_ENABLED_COMBI_MODE 0x300000000
#define BOOTGUARD_CAPABILITY(x) ( \
		( (x) == BOOTGUARD_DISABLED ) || \
		( (x) == BOOTGUARD_ENABLED_VERIFIED_MODE ) || \
		( (x) == BOOTGUARD_ENABLED_MEASUREMENT_MODE ) || \
		( (x) == BOOTGUARD_ENABLED_COMBI_MODE ))

#ifndef __DARWIN__

typedef struct {
	unsigned int ebx;
	unsigned int edx;
	unsigned int ecx;
} regs_t;

extern int msr_bootguard(uint64_t *msr, int debug);
#endif
