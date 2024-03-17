/*
 * Copyright (c) 2021 Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "c2000ware_libraries.h"


void C2000Ware_libraries_init()
{
    CONTROLLER_init();
}


//
// DCL CONTROLLER
//
//
// myCONTROLLER0 variables
//
DCL_PI myCONTROLLER0 = PI_DEFAULTS;
DCL_PI_SPS myCONTROLLER0_sps = PI_SPS_DEFAULTS;
DCL_CSS myCONTROLLER0_css = DCL_CSS_DEFAULTS;
void myCONTROLLER0_init(){
    //
    // myCONTROLLER0 settings
    //
    myCONTROLLER0.sps = &myCONTROLLER0_sps;
    myCONTROLLER0.css = &myCONTROLLER0_css;
    myCONTROLLER0.Kp = 11.5f;
    myCONTROLLER0.Ki = 0.01f;
    myCONTROLLER0.i10 = 1.0f;
    myCONTROLLER0.Umax = 200.0f;
    myCONTROLLER0.Umin = 50.0f;
    myCONTROLLER0.i6 = 1.0f;
    myCONTROLLER0.i11 = 1.0f;
    myCONTROLLER0.Imax = 1.0f;
    myCONTROLLER0.Imin = -1.0f;
}
void CONTROLLER_init(){
    myCONTROLLER0_init();
}

