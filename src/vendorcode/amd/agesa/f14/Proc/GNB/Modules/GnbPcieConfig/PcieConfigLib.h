/* $NoKeywords:$ */
/**
 * @file
 *
 * GNB function to create/locate PCIe configuration data area
 *
 * Contain code that create/locate and rebase configuration data area.
 *
 * @xrefitem bom "File Content Label" "Release Content"
 * @e project:     AGESA
 * @e sub-project: GNB
 * @e \$Revision: 38519 $   @e \$Date: 2010-09-24 17:08:48 -0700 (Fri, 24 Sep 2010) $
 *
 */
/*
 *****************************************************************************
 *
 * Copyright (c) 2011, Advanced Micro Devices, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Advanced Micro Devices, Inc. nor the names of
 *       its contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ADVANCED MICRO DEVICES, INC. BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ***************************************************************************
 *
 */

#ifndef _PCIECONFIGLIB_H_
#define _PCIECONFIGLIB_H_

typedef VOID (*PCIe_RUN_ON_ENGINE_CALLBACK) (
  IN      PCIe_ENGINE_CONFIG            *Engine,
  IN OUT  VOID                          *Buffer,
  IN      PCIe_PLATFORM_CONFIG          *Pcie
  );

typedef AGESA_STATUS (*PCIe_RUN_ON_WRAPPER_CALLBACK) (
  IN      PCIe_WRAPPER_CONFIG           *Wrapper,
  IN OUT  VOID                          *Buffer,
  IN      PCIe_PLATFORM_CONFIG          *Pcie
  );

UINT8
PcieConfigGetNumberOfCoreLane (
  IN      PCIe_ENGINE_CONFIG    *Engine
  );

VOID
PcieConfigDisableAllEngines (
  IN      UINTN                 EngineTypeMask,
  IN      PCIe_WRAPPER_CONFIG   *Wrapper
  );

VOID
PcieConfigDisableEngine (
  IN      PCIe_ENGINE_CONFIG    *Engine
  );

UINT32
PcieConfigGetEnginePhyLaneBitMap (
  IN      PCIe_ENGINE_CONFIG    *Engine
  );

UINT8
PcieConfigGetNumberOfPhyLane (
  IN      PCIe_ENGINE_CONFIG    *Engine
  );

UINT64
PcieConfigGetConfigurationSignature (
  IN      PCIe_WRAPPER_CONFIG   *Wrapper,
  IN      UINT8                 CoreId
  );

BOOLEAN
PcieConfigCheckPortStatus (
  IN       PCIe_ENGINE_CONFIG    *Engine,
  IN       UINT32                PortStatus
  );

UINT32
PcieConfigUpdatePortStatus (
  IN       PCIe_ENGINE_CONFIG    *Engine,
  IN       UINT32                SetStatus,
  IN       UINT32                ResetStatus
  );

VOID
PcieConfigRunProcForAllEngines (
  IN       UINT32                        DescriptorFlags,
  IN       PCIe_RUN_ON_ENGINE_CALLBACK   Callback,
  IN OUT   VOID                          *Buffer,
  IN       PCIe_PLATFORM_CONFIG          *Pcie
  );

AGESA_STATUS
PcieConfigRunProcForAllWrappers (
  IN       UINT32                        DescriptorFlags,
  IN       PCIe_RUN_ON_WRAPPER_CALLBACK  Callback,
  IN OUT   VOID                          *Buffer,
  IN       PCIe_PLATFORM_CONFIG          *Pcie
  );
#endif

