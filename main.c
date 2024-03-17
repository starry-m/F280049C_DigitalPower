// #############################################################################
//
//  FILE:    gpio_ex2_toggle.c
//
//  TITLE:   Device GPIO Toggle
//
//! \addtogroup driver_example_list
//! <h1> Device GPIO Toggle </h1>
//!
//! Configures the device GPIO through the sysconfig file. The GPIO pin is
//! toggled in the infinite loop.
//! In order to migrate the project within syscfg to any device,
//! click the swtich button under the device view and select your
//! corresponding device to migrate, saving the project will
//! auto-migrate your project settings.
//
// #############################################################################
//
//
// $Copyright:
// Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
//   Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
//
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the
//   distribution.
//
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
// #############################################################################

//
// Included Files
//
#include "driverlib.h"
#include "device.h"
#include "board.h"
#include "c2000ware_libraries.h"
#include "stdio.h"


#include "drv_oled.h"
//
// Globals
//

uint32_t isr_counter = 0;
uint16_t counter = 0;
uint8_t time_flag = 0;
unsigned char *msg;

volatile float32_t Vin_temp = 0.0;
volatile float32_t I_in_temp = 0.0;
volatile float32_t I_L_temp = 0.0;

volatile float32_t Vout_temp = 0.0;
volatile float32_t I_out_temp = 0.0;

uint16_t compBValue = 0;
uint32_t LOOP_counter = 0;

volatile float32_t vtarget = 5.0;
//
// Main
//
void main(void)
{
    //
    // Initializes system control, device clock, and peripherals
    //
    Device_init();

    //
    // Initializes PIE and clear PIE registers. Disables CPU interrupts.
    // and clear all CPU interrupt flags.
    //
    Interrupt_initModule();

    //
    // Initialize the PIE vector table with pointers to the shell interrupt
    // Service Routines (ISR).
    //
    Interrupt_initVectorTable();

    //
    // Disable sync(Freeze clock to PWM as well)
    //
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
    Board_init();
    C2000Ware_libraries_init();
    //
    // Enable sync and clock to PWM
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

    //
    // Enable ePWM interrupts
    //
    Interrupt_enable(INT_EPWM1);

    msg = "\r\n--F280048C-Digital Power--\n\0";
    SCI_writeCharArray(SCIA_BASE, (uint16_t *)msg, 31);
    msg = "\r\nyou can send 2 characters to set voltage,such as :“51” ->set:5.1V\n\0";
    SCI_writeCharArray(SCIA_BASE, (uint16_t *)msg, 74);
    SCI_setFIFOInterruptLevel(SCIA_BASE, SCI_FIFO_TX0, SCI_FIFO_RX2);
    SCI_enableInterrupt(SCIA_BASE, SCI_INT_TXFF | SCI_INT_RXFF);

    //         Clear the SCI interrupts before enabling them.
    SCI_clearInterruptStatus(SCIA_BASE, SCI_INT_TXFF | SCI_INT_RXFF);
    //
    // Enable the interrupts in the PIE: Group 9 interrupts 1 & 2.
    //
    Interrupt_enable(INT_SCIA_RX);
    Interrupt_enable(INT_SCIA_TX);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);
    //
    // Enable Global Interrupt (INTM) and realtime interrupt (DBGM)
    //
    EINT;
    ERTM;

    Oled_Init();
    OLED_DISPLAY_INT();
    GPIO_writePin(30, 1);
    GPIO_writePin(58, 1);
    uint16_t Vin_temp22 = 0.0;
    uint16_t Vout_temp22 = 0.0;
    msg = "\r\n\n\nHello World!\0";
    SCI_writeCharArray(SCIA_BASE, (uint16_t *)msg, 17);
    for (;;)
    {
        if (time_flag)
        {
            time_flag = 0;
            GPIO_togglePin(34);
            GPIO_togglePin(58);
            LOOP_counter++;
        }
        Vin_temp22 = (uint16_t)(Vin_temp * 10);
        Vout_temp22 = (uint16_t)(Vout_temp * 10);
        OLED_ShowNum(50, 0, Vin_temp22 / 10, 2, 16);
        OLED_ShowNum(74, 0, Vin_temp22 % 10, 1, 16);
        OLED_ShowNum(50, 2, Vout_temp22 / 10, 2, 16);
        OLED_ShowNum(74, 2, Vout_temp22 % 10, 1, 16);
        DEVICE_DELAY_US(100000);
    }
}
uint16_t Sample_Temp;
//
// epwm1ISR - ePWM 1 ISR
//
#pragma CODE_SECTION(INT_myEPWM0_ISR, "ramfuncs");
__interrupt void INT_myEPWM0_ISR(void)
{

    isr_counter++;
    if (isr_counter == 2000)
    {
        GPIO_togglePin(23);
        isr_counter = 0;
        time_flag = 1;
    }
    Sample_Temp = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER0);
    I_L_temp = (Sample_Temp * 3300.0 / 4096) * 0.00757575f;
    Sample_Temp = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER1);
    Vin_temp = (Sample_Temp * 3300.0 / 4096) * 0.011f;
    Sample_Temp = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER2);
    I_in_temp = (Sample_Temp * 3300.0 / 4096) * 0.00757575f - 12.49998f;

    Sample_Temp = ADC_readResult(ADCBRESULT_BASE, ADC_SOC_NUMBER0);
    Vout_temp = (Sample_Temp * 3300.0 / 4096) * 0.011f;

    Sample_Temp = ADC_readResult(ADCBRESULT_BASE, ADC_SOC_NUMBER1);
    I_out_temp = (Sample_Temp * 3300.0 / 4096) * 0.00757575f - 12.49998f;

    compBValue = (uint16_t)DCL_runPI_C1(&myCONTROLLER0, vtarget, Vout_temp);

    EPWM_setCounterCompareValue(myEPWM0_BASE, EPWM_COUNTER_COMPARE_A, compBValue);
    //
    // Clear INT flag for this timer
    //
    EPWM_clearEventTriggerInterruptFlag(myEPWM0_BASE);

    //
    // Acknowledge interrupt group
    //
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP3);
}
//
// sciaTxISR - Disable the TXFF interrupt and print message asking
//             for two characters.
//
__interrupt void INT_mySCI0_TX_ISR(void)
{
    //
    // Disable the TXRDY interrupt.
    //
    SCI_disableInterrupt(SCIA_BASE, SCI_INT_TXFF);

    //    msg = "\r\nEnter two characters: \0";
    //    SCI_writeCharArray(SCIA_BASE, (uint16_t*)msg, 26);

    //
    // Acknowledge the PIE interrupt.
    //
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);
}

//
// sciaRxISR - Read two characters from the RXBUF and echo them back.
//
__interrupt void INT_mySCI0_RX_ISR(void)
{
    uint16_t receivedChar1, receivedChar2;

    //
    // Enable the TXFF interrupt again.
    //
    SCI_enableInterrupt(SCIA_BASE, SCI_INT_TXFF);

    //
    // Read two characters from the FIFO.
    //
    receivedChar1 = SCI_readCharBlockingFIFO(SCIA_BASE);
    receivedChar2 = SCI_readCharBlockingFIFO(SCIA_BASE);

    //
    // Echo back the two characters.
    //
    msg = "  You sent: \0";
    SCI_writeCharArray(SCIA_BASE, (uint16_t *)msg, 13);
    SCI_writeCharBlockingFIFO(SCIA_BASE, receivedChar1);
    SCI_writeCharBlockingFIFO(SCIA_BASE, receivedChar2);
    vtarget = (receivedChar1 - '0') + (receivedChar2 - '0') / 10.0;
    //
    // Clear the SCI RXFF interrupt and acknowledge the PIE interrupt.
    //
    SCI_clearInterruptStatus(SCIA_BASE, SCI_INT_RXFF);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);

    counter++;
}
