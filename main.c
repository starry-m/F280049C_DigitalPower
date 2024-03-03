//#############################################################################
//
// FILE:    gpio_ex2_toggle.c
//
// TITLE:   Device GPIO Toggle
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
//#############################################################################
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
//#############################################################################

//
// Included Files
//
#include "driverlib.h"
#include "device.h"
#include "board.h"

#include "stdint.h"
//
// Globals
//
EPWM_SignalParams pwmSignal =
            {100000, 0.5f, 0.5f, true, DEVICE_SYSCLK_FREQ,
            EPWM_COUNTER_MODE_UP_DOWN, EPWM_CLOCK_DIVIDER_1,
            EPWM_HSCLOCK_DIVIDER_1};

uint32_t isr_counter=0;
uint16_t counter = 0;
unsigned char *msg;
#define RESULTS_BUFFER_SIZE     256

//
// Globals
//
uint16_t myADC0Results[RESULTS_BUFFER_SIZE];   // Buffer for results
uint16_t index;                              // Index into result buffer
volatile uint16_t bufferFull;                // Flag to indicate buffer is full

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
    // Disable pin locks and enable internal pull ups.
    //
//    Device_initGPIO();
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


//        EPWM_configureSignal(myEPWM0_BASE, &pwmSignal);

        //
        // Enable sync and clock to PWM
        //
        SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

        //
        // Enable ePWM interrupts
        //
        Interrupt_enable(INT_EPWM1);

        ADC_setOffsetTrimAll(ADC_REFERENCE_INTERNAL,ADC_REFERENCE_3_3V);
        //
        // Initialize results buffer
        //
        for(index = 0; index < RESULTS_BUFFER_SIZE; index++)
        {
            myADC0Results[index] = 0;
        }

        index = 0;
        bufferFull = 0;
        //
        // Send starting message.
        //
        msg = "\r\n\n\nHello World!\0";
        SCI_writeCharArray(SCIA_BASE, (uint16_t*)msg, 17);
        msg = "\r\nYou will enter a character, and the DSP will echo it back!\n\0";
        SCI_writeCharArray(SCIA_BASE, (uint16_t*)msg, 62);

//        SCI_setFIFOInterruptLevel(SCIA_BASE, SCI_FIFO_TX0, SCI_FIFO_RX2);
        SCI_enableInterrupt(SCIA_BASE, SCI_INT_TXFF | SCI_INT_RXFF);
        //
        // Clear the SCI interrupts before enabling them.
        //
//        SCI_clearInterruptStatus(SCIA_BASE, SCI_INT_TXFF | SCI_INT_RXFF);
//
//        //
//        // Enable the interrupts in the PIE: Group 9 interrupts 1 & 2.
//        //
//        Interrupt_enable(INT_SCIA_RX);
//        Interrupt_enable(INT_SCIA_TX);
        Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);
    //
    // Enable Global Interrupt (INTM) and realtime interrupt (DBGM)
    //
    EINT;
    ERTM;
    //
    // Loop.
    //
    uint16_t compAValue=10;
    char send_ad_buff[20];
    uint16_t ai;
    for(ai=0;ai<9;ai++)
    {
        printf(send_ad_buff,"adc %d: = %d\n",ai,myADC0Results[ai]);
//        SCI_writeCharArray(SCIA_BASE, (uint16_t*)send_ad_buff, 12);
    }
    for(;;)
    {
//        GPIO_togglePin(23);
        DEVICE_DELAY_US(500000);
        GPIO_togglePin(34);
//        EPWM_setCounterCompareValue(myEPWM0_BASE,EPWM_COUNTER_COMPARE_A,compAValue);
        if(compAValue<240)
            compAValue+=10;
        else
            compAValue=0;



    }
}
//
// epwm1ISR - ePWM 1 ISR
//
__interrupt void INT_myEPWM0_ISR(void)
{

    isr_counter++;
    if(isr_counter==200000)
    {
        GPIO_togglePin(23);
        isr_counter=0;
    }
    if(index<7)
    {
        myADC0Results[index++] = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER0);
        myADC0Results[index++] = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER1);
        myADC0Results[index++] = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER2);
    }
    else
        index=0;
//    EPWM_setCounterCompareValue(myEPWM0_BASE,EPWM_COUNTER_COMPARE_A,isr_counter%250);
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

    msg = "\r\nEnter two characters: \0";
    SCI_writeCharArray(SCIA_BASE, (uint16_t*)msg, 26);

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
    SCI_writeCharArray(SCIA_BASE, (uint16_t*)msg, 13);
    SCI_writeCharBlockingFIFO(SCIA_BASE, receivedChar1);
    SCI_writeCharBlockingFIFO(SCIA_BASE, receivedChar2);

    //
    // Clear the SCI RXFF interrupt and acknowledge the PIE interrupt.
    //
    SCI_clearInterruptStatus(SCIA_BASE, SCI_INT_RXFF);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);

    counter++;
}
//
// End of File
//

