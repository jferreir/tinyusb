/*
 * hcd.h
 *
 *  Created on: Nov 26, 2012
 *      Author: hathach
 */

/*
 * Software License Agreement (BSD License)
 * Copyright (c) 2013, hathach (tinyusb.net)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the tinyUSB stack.
 */

/** \file
 *  \brief Host Controller Driver
 *
 *  \note TBD
 */

/** 
 *  \defgroup Group_HCD Host Controller Driver
 *  \brief Host Controller Driver
 *
 *  @{
 */

#ifndef _TUSB_HCD_H_
#define _TUSB_HCD_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "common/common.h"

typedef uint32_t pipe_handle_t;


tusb_error_t hcd_init(uint8_t hostid) ATTR_WARN_UNUSED_RESULT;

//--------------------------------------------------------------------+
// PIPE API
//--------------------------------------------------------------------+
pipe_handle_t hcd_pipe_addr0_open(uint8_t core_id, tusb_speed_t speed, uint8_t hub_addr, uint8_t hub_port);

pipe_handle_t hcd_pipe_control_open(uint8_t dev_addr, uint8_t max_packet_size);
tusb_error_t  hcd_pipe_control_xfer(pipe_handle_t pipe_hdl, const tusb_std_request_t * const p_request, uint8_t data[]);
pipe_handle_t hcd_pipe_open(uint8_t dev_addr, tusb_descriptor_endpoint_t* endpoint_desc);

#if 0
//tusb_error_t hcd_pipe_open(
//    uint8_t hostid, uint8_t device_address,
//
//    )ATTR_WARN_UNUSED_RESULT;
tusb_error_t hcd_pipe_close()ATTR_WARN_UNUSED_RESULT;
tusb_error_t hcd_pipe_transfer()ATTR_WARN_UNUSED_RESULT;
tusb_error_t hcd_pipe_cancel()ATTR_WARN_UNUSED_RESULT;
#endif

//--------------------------------------------------------------------+
// PORT API
//--------------------------------------------------------------------+
/// return the current connect status of roothub port
bool hcd_port_connect_status(uint8_t core_id) ATTR_WARN_UNUSED_RESULT;
tusb_speed_t hcd_port_speed(uint8_t core_id) ATTR_WARN_UNUSED_RESULT;

#ifdef __cplusplus
 }
#endif

 #endif /* _TUSB_HCD_H_ */

/// @}
