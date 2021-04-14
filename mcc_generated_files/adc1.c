/**
  ADC1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    adc1.c

  @Summary
    This is the generated driver implementation file for the ADC1 driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This source file provides APIs for ADC1.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.169.0
        Device            :  dsPIC33CK256MP508      
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.50
        MPLAB 	          :  MPLAB X v5.40
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/

#include "adc1.h"

/**
 Section: File specific functions
*/

static void (*ADC1_CommonDefaultInterruptHandler)(void);
static void (*ADC1_CH_AN2_TEMPEXTDefaultInterruptHandler)(uint16_t adcVal);
static void (*ADC1_CH_AN4_IBUSDefaultInterruptHandler)(uint16_t adcVal);
static void (*ADC1_CH_AN11_POTDefaultInterruptHandler)(uint16_t adcVal);
static void (*ADC1_CH_AN12_TEMPLOCALDefaultInterruptHandler)(uint16_t adcVal);
static void (*ADC1_CH_AN15_VBUSDefaultInterruptHandler)(uint16_t adcVal);
static void (*ADC1_CH_AN17_VADefaultInterruptHandler)(uint16_t adcVal);
static void (*ADC1_CH_AN22_VCDefaultInterruptHandler)(uint16_t adcVal);
static void (*ADC1_CH_AN23_VBDefaultInterruptHandler)(uint16_t adcVal);
static void (*ADC1_CH_AN0_IADefaultInterruptHandler)(uint16_t adcVal);
static void (*ADC1_CH_AN1_IBDefaultInterruptHandler)(uint16_t adcVal);

/**
  Section: Driver Interface
*/

void ADC1_Initialize (void)
{
    // ADSIDL disabled; ADON enabled; 
    ADCON1L = (0x8000 & 0x7FFF); //Disabling ADON bit
    // FORM Fractional; SHRRES 12-bit resolution; 
    ADCON1H = 0xE0;
    // PTGEN disabled; SHRADCS 4; REFCIE disabled; SHREISEL Early interrupt is generated 1 TADCORE clock prior to data being ready; REFERCIE disabled; EIEN disabled; 
    ADCON2L = 0x02;
    // SHRSAMC 3; 
    ADCON2H = 0x03;
    // SWCTRG disabled; SHRSAMP disabled; SUSPEND disabled; SWLCTRG disabled; SUSPCIE disabled; CNVCHSEL AN0; REFSEL disabled; 
    ADCON3L = 0x00;
    // SHREN enabled; C1EN enabled; C0EN enabled; CLKDIV 4; CLKSEL PLL VCO/4; 
    ADCON3H = (0xC383 & 0xFF00); //Disabling C0EN, C1EN, C2EN, C3EN and SHREN bits
    // SAMC0EN disabled; SAMC1EN disabled; 
    ADCON4L = 0x00;
    // C0CHS AN0; C1CHS AN1; 
    ADCON4H = 0x00;
    // SIGN0 enabled; SIGN4 disabled; SIGN3 disabled; SIGN2 disabled; SIGN1 enabled; SIGN7 disabled; SIGN6 disabled; DIFF0 disabled; SIGN5 disabled; DIFF1 disabled; DIFF2 disabled; DIFF3 disabled; DIFF4 enabled; DIFF5 disabled; DIFF6 disabled; DIFF7 disabled; 
    ADMOD0L = 0x205;
    // DIFF15 disabled; DIFF14 disabled; SIGN8 disabled; DIFF13 disabled; SIGN14 disabled; DIFF12 disabled; SIGN15 disabled; DIFF11 disabled; DIFF10 disabled; SIGN9 disabled; DIFF8 disabled; DIFF9 disabled; SIGN10 disabled; SIGN11 disabled; SIGN12 disabled; SIGN13 disabled; 
    ADMOD0H = 0x00;
    // DIFF19 disabled; DIFF18 disabled; DIFF17 disabled; DIFF16 disabled; DIFF23 disabled; SIGN16 disabled; DIFF22 disabled; SIGN17 disabled; DIFF21 disabled; SIGN18 disabled; DIFF20 disabled; SIGN19 enabled; SIGN20 disabled; SIGN21 disabled; SIGN22 disabled; SIGN23 disabled; 
    ADMOD1L = 0x40;
    // SIGN24 disabled; DIFF25 disabled; DIFF24 disabled; SIGN25 disabled; 
    ADMOD1H = 0x00;
    // IE15 disabled; IE1 disabled; IE0 enabled; IE3 disabled; IE2 disabled; IE5 disabled; IE4 disabled; IE10 disabled; IE7 disabled; IE6 disabled; IE9 disabled; IE13 disabled; IE8 disabled; IE14 disabled; IE11 disabled; IE12 disabled; 
    ADIEL = 0x01;
    // IE17 disabled; IE18 disabled; IE16 disabled; IE19 disabled; IE20 disabled; IE21 disabled; IE24 disabled; IE25 disabled; IE22 disabled; IE23 disabled; 
    ADIEH = 0x00;
    // CMPEN10 disabled; CMPEN11 disabled; CMPEN6 disabled; CMPEN5 disabled; CMPEN4 disabled; CMPEN3 disabled; CMPEN2 disabled; CMPEN1 disabled; CMPEN0 disabled; CMPEN14 disabled; CMPEN9 disabled; CMPEN15 disabled; CMPEN8 disabled; CMPEN12 disabled; CMPEN7 disabled; CMPEN13 disabled; 
    ADCMP0ENL = 0x00;
    // CMPEN10 disabled; CMPEN11 disabled; CMPEN6 disabled; CMPEN5 disabled; CMPEN4 disabled; CMPEN3 disabled; CMPEN2 disabled; CMPEN1 disabled; CMPEN0 disabled; CMPEN14 disabled; CMPEN9 disabled; CMPEN15 disabled; CMPEN8 disabled; CMPEN12 disabled; CMPEN7 disabled; CMPEN13 disabled; 
    ADCMP1ENL = 0x00;
    // CMPEN10 disabled; CMPEN11 disabled; CMPEN6 disabled; CMPEN5 disabled; CMPEN4 disabled; CMPEN3 disabled; CMPEN2 disabled; CMPEN1 disabled; CMPEN0 disabled; CMPEN14 disabled; CMPEN9 disabled; CMPEN15 disabled; CMPEN8 disabled; CMPEN12 disabled; CMPEN7 disabled; CMPEN13 disabled; 
    ADCMP2ENL = 0x00;
    // CMPEN10 disabled; CMPEN11 disabled; CMPEN6 disabled; CMPEN5 disabled; CMPEN4 disabled; CMPEN3 disabled; CMPEN2 disabled; CMPEN1 disabled; CMPEN0 disabled; CMPEN14 disabled; CMPEN9 disabled; CMPEN15 disabled; CMPEN8 disabled; CMPEN12 disabled; CMPEN7 disabled; CMPEN13 disabled; 
    ADCMP3ENL = 0x00;
    // CMPEN21 disabled; CMPEN22 disabled; CMPEN20 disabled; CMPEN18 disabled; CMPEN19 disabled; CMPEN16 disabled; CMPEN17 disabled; CMPEN25 disabled; CMPEN23 disabled; CMPEN24 disabled; 
    ADCMP0ENH = 0x00;
    // CMPEN21 disabled; CMPEN22 disabled; CMPEN20 disabled; CMPEN18 disabled; CMPEN19 disabled; CMPEN16 disabled; CMPEN17 disabled; CMPEN25 disabled; CMPEN23 disabled; CMPEN24 disabled; 
    ADCMP1ENH = 0x00;
    // CMPEN21 disabled; CMPEN22 disabled; CMPEN20 disabled; CMPEN18 disabled; CMPEN19 disabled; CMPEN16 disabled; CMPEN17 disabled; CMPEN25 disabled; CMPEN23 disabled; CMPEN24 disabled; 
    ADCMP2ENH = 0x00;
    // CMPEN21 disabled; CMPEN22 disabled; CMPEN20 disabled; CMPEN18 disabled; CMPEN19 disabled; CMPEN16 disabled; CMPEN17 disabled; CMPEN25 disabled; CMPEN23 disabled; CMPEN24 disabled; 
    ADCMP3ENH = 0x00;
    // CMPLO 0; 
    ADCMP0LO = 0x00;
    // CMPLO 0; 
    ADCMP1LO = 0x00;
    // CMPLO 0; 
    ADCMP2LO = 0x00;
    // CMPLO 0; 
    ADCMP3LO = 0x00;
    // CMPHI 0; 
    ADCMP0HI = 0x00;
    // CMPHI 0; 
    ADCMP1HI = 0x00;
    // CMPHI 0; 
    ADCMP2HI = 0x00;
    // CMPHI 0; 
    ADCMP3HI = 0x00;
    // OVRSAM 2x; MODE Oversampling Mode; FLCHSEL AN0; IE disabled; FLEN disabled; 
    ADFL0CON = 0x00;
    // OVRSAM 2x; MODE Oversampling Mode; FLCHSEL AN0; IE disabled; FLEN disabled; 
    ADFL1CON = 0x00;
    // OVRSAM 2x; MODE Oversampling Mode; FLCHSEL AN0; IE disabled; FLEN disabled; 
    ADFL2CON = 0x00;
    // OVRSAM 2x; MODE Oversampling Mode; FLCHSEL AN0; IE disabled; FLEN disabled; 
    ADFL3CON = 0x00;
    // HIHI disabled; LOLO disabled; HILO disabled; BTWN disabled; LOHI disabled; CMPEN disabled; IE disabled; 
    ADCMP0CON = 0x00;
    // HIHI disabled; LOLO disabled; HILO disabled; BTWN disabled; LOHI disabled; CMPEN disabled; IE disabled; 
    ADCMP1CON = 0x00;
    // HIHI disabled; LOLO disabled; HILO disabled; BTWN disabled; LOHI disabled; CMPEN disabled; IE disabled; 
    ADCMP2CON = 0x00;
    // HIHI disabled; LOLO disabled; HILO disabled; BTWN disabled; LOHI disabled; CMPEN disabled; IE disabled; 
    ADCMP3CON = 0x00;
    // LVLEN9 disabled; LVLEN8 disabled; LVLEN11 disabled; LVLEN7 disabled; LVLEN10 disabled; LVLEN6 disabled; LVLEN13 disabled; LVLEN5 disabled; LVLEN12 disabled; LVLEN4 disabled; LVLEN15 disabled; LVLEN3 disabled; LVLEN14 disabled; LVLEN2 disabled; LVLEN1 disabled; LVLEN0 disabled; 
    ADLVLTRGL = 0x00;
    // LVLEN20 disabled; LVLEN22 disabled; LVLEN21 disabled; LVLEN24 disabled; LVLEN23 disabled; LVLEN25 disabled; LVLEN17 disabled; LVLEN16 disabled; LVLEN19 disabled; LVLEN18 disabled; 
    ADLVLTRGH = 0x00;
    // SAMC 8; 
    ADCORE0L = 0x08;
    // SAMC 8; 
    ADCORE1L = 0x08;
    // RES 12-bit resolution; EISEL Early interrupt is generated 1 TADCORE clock prior to data being ready; ADCS 4; 
    ADCORE0H = 0x302;
    // RES 12-bit resolution; EISEL Early interrupt is generated 1 TADCORE clock prior to data being ready; ADCS 4; 
    ADCORE1H = 0x302;
    // EIEN9 disabled; EIEN7 disabled; EIEN8 disabled; EIEN5 disabled; EIEN6 disabled; EIEN3 disabled; EIEN4 disabled; EIEN1 disabled; EIEN2 disabled; EIEN13 disabled; EIEN0 disabled; EIEN12 disabled; EIEN11 disabled; EIEN10 disabled; EIEN15 disabled; EIEN14 disabled; 
    ADEIEL = 0x00;
    // EIEN17 disabled; EIEN16 disabled; EIEN25 disabled; EIEN19 disabled; EIEN18 disabled; EIEN20 disabled; EIEN24 disabled; EIEN23 disabled; EIEN22 disabled; EIEN21 disabled; 
    ADEIEH = 0x00;
    // C0CIE disabled; C1CIE disabled; SHRCIE disabled; WARMTIME 32768 Source Clock Periods; 
    ADCON5H = (0x1500 & 0xF0FF); //Disabling WARMTIME bit
	
    //Assign Default Callbacks
    ADC1_SetCommonInterruptHandler(&ADC1_CallBack);
    ADC1_SetCH_AN2_TEMPEXTInterruptHandler(&ADC1_CH_AN2_TEMPEXT_CallBack);
    ADC1_SetCH_AN4_IBUSInterruptHandler(&ADC1_CH_AN4_IBUS_CallBack);
    ADC1_SetCH_AN11_POTInterruptHandler(&ADC1_CH_AN11_POT_CallBack);
    ADC1_SetCH_AN12_TEMPLOCALInterruptHandler(&ADC1_CH_AN12_TEMPLOCAL_CallBack);
    ADC1_SetCH_AN15_VBUSInterruptHandler(&ADC1_CH_AN15_VBUS_CallBack);
    ADC1_SetCH_AN17_VAInterruptHandler(&ADC1_CH_AN17_VA_CallBack);
    ADC1_SetCH_AN22_VCInterruptHandler(&ADC1_CH_AN22_VC_CallBack);
    ADC1_SetCH_AN23_VBInterruptHandler(&ADC1_CH_AN23_VB_CallBack);
    ADC1_SetCH_AN0_IAInterruptHandler(&ADC1_CH_AN0_IA_CallBack);
    ADC1_SetCH_AN1_IBInterruptHandler(&ADC1_CH_AN1_IB_CallBack);
    
    // Clearing CH_AN0_IA interrupt flag.
    IFS5bits.ADCAN0IF = 0;
    // Enabling CH_AN0_IA interrupt.
    IEC5bits.ADCAN0IE = 1;

    // Setting WARMTIME bit
    ADCON5Hbits.WARMTIME = 0xF;
    // Enabling ADC Module
    ADCON1Lbits.ADON = 0x1;
    // Enabling Power for the Shared Core
    ADC1_SharedCorePowerEnable();
    // Enabling Power for Core0
    ADC1_Core0PowerEnable();
    // Enabling Power for Core1
    ADC1_Core1PowerEnable();

    //TRGSRC0 PWM1 Trigger1; TRGSRC1 PWM1 Trigger1; 
    ADTRIG0L = 0x404;
    //TRGSRC3 None; TRGSRC2 PWM1 Trigger1; 
    ADTRIG0H = 0x04;
    //TRGSRC4 PWM1 Trigger1; TRGSRC5 None; 
    ADTRIG1L = 0x04;
    //TRGSRC6 None; TRGSRC7 None; 
    ADTRIG1H = 0x00;
    //TRGSRC8 None; TRGSRC9 None; 
    ADTRIG2L = 0x00;
    //TRGSRC11 PWM1 Trigger1; TRGSRC10 None; 
    ADTRIG2H = 0x400;
    //TRGSRC13 None; TRGSRC12 PWM1 Trigger1; 
    ADTRIG3L = 0x04;
    //TRGSRC15 PWM1 Trigger1; TRGSRC14 None; 
    ADTRIG3H = 0x400;
    //TRGSRC17 PWM1 Trigger1; TRGSRC16 None; 
    ADTRIG4L = 0x400;
    //TRGSRC19 None; TRGSRC18 None; 
    ADTRIG4H = 0x00;
    //TRGSRC20 None; TRGSRC21 None; 
    ADTRIG5L = 0x00;
    //TRGSRC22 PWM1 Trigger1; TRGSRC23 PWM1 Trigger1; 
    ADTRIG5H = 0x404;
    //TRGSRC24 None; TRGSRC25 None; 
    ADTRIG6L = 0x00;
}

void ADC1_Core0PowerEnable ( ) 
{
    ADCON5Lbits.C0PWR = 1; 
    while(ADCON5Lbits.C0RDY == 0);
    ADCON3Hbits.C0EN = 1;     
}

void ADC1_Core1PowerEnable ( ) 
{
    ADCON5Lbits.C1PWR = 1; 
    while(ADCON5Lbits.C1RDY == 0);
    ADCON3Hbits.C1EN = 1;     
}

void ADC1_SharedCorePowerEnable ( ) 
{
    ADCON5Lbits.SHRPWR = 1;   
    while(ADCON5Lbits.SHRRDY == 0);
    ADCON3Hbits.SHREN = 1;   
}


void __attribute__ ((weak)) ADC1_CallBack ( void )
{ 

}

void ADC1_SetCommonInterruptHandler(void* handler)
{
    ADC1_CommonDefaultInterruptHandler = handler;
}

void __attribute__ ((weak)) ADC1_Tasks ( void )
{
    if(IFS5bits.ADCIF)
    {
        if(ADC1_CommonDefaultInterruptHandler) 
        { 
            ADC1_CommonDefaultInterruptHandler(); 
        }

        // clear the ADC1 interrupt flag
        IFS5bits.ADCIF = 0;
    }
}

void __attribute__ ((weak)) ADC1_CH_AN2_TEMPEXT_CallBack( uint16_t adcVal )
{ 

}

void ADC1_SetCH_AN2_TEMPEXTInterruptHandler(void* handler)
{
    ADC1_CH_AN2_TEMPEXTDefaultInterruptHandler = handler;
}

void __attribute__ ((weak)) ADC1_CH_AN2_TEMPEXT_Tasks ( void )
{
    uint16_t valCH_AN2_TEMPEXT;

    if(ADSTATLbits.AN2RDY)
    {
        //Read the ADC value from the ADCBUF
        valCH_AN2_TEMPEXT = ADCBUF2;

        if(ADC1_CH_AN2_TEMPEXTDefaultInterruptHandler) 
        { 
            ADC1_CH_AN2_TEMPEXTDefaultInterruptHandler(valCH_AN2_TEMPEXT); 
        }
    }
}

void __attribute__ ((weak)) ADC1_CH_AN4_IBUS_CallBack( uint16_t adcVal )
{ 

}

void ADC1_SetCH_AN4_IBUSInterruptHandler(void* handler)
{
    ADC1_CH_AN4_IBUSDefaultInterruptHandler = handler;
}

void __attribute__ ((weak)) ADC1_CH_AN4_IBUS_Tasks ( void )
{
    uint16_t valCH_AN4_IBUS;

    if(ADSTATLbits.AN4RDY)
    {
        //Read the ADC value from the ADCBUF
        valCH_AN4_IBUS = ADCBUF4;

        if(ADC1_CH_AN4_IBUSDefaultInterruptHandler) 
        { 
            ADC1_CH_AN4_IBUSDefaultInterruptHandler(valCH_AN4_IBUS); 
        }
    }
}

void __attribute__ ((weak)) ADC1_CH_AN11_POT_CallBack( uint16_t adcVal )
{ 

}

void ADC1_SetCH_AN11_POTInterruptHandler(void* handler)
{
    ADC1_CH_AN11_POTDefaultInterruptHandler = handler;
}

void __attribute__ ((weak)) ADC1_CH_AN11_POT_Tasks ( void )
{
    uint16_t valCH_AN11_POT;

    if(ADSTATLbits.AN11RDY)
    {
        //Read the ADC value from the ADCBUF
        valCH_AN11_POT = ADCBUF11;

        if(ADC1_CH_AN11_POTDefaultInterruptHandler) 
        { 
            ADC1_CH_AN11_POTDefaultInterruptHandler(valCH_AN11_POT); 
        }
    }
}

void __attribute__ ((weak)) ADC1_CH_AN12_TEMPLOCAL_CallBack( uint16_t adcVal )
{ 

}

void ADC1_SetCH_AN12_TEMPLOCALInterruptHandler(void* handler)
{
    ADC1_CH_AN12_TEMPLOCALDefaultInterruptHandler = handler;
}

void __attribute__ ((weak)) ADC1_CH_AN12_TEMPLOCAL_Tasks ( void )
{
    uint16_t valCH_AN12_TEMPLOCAL;

    if(ADSTATLbits.AN12RDY)
    {
        //Read the ADC value from the ADCBUF
        valCH_AN12_TEMPLOCAL = ADCBUF12;

        if(ADC1_CH_AN12_TEMPLOCALDefaultInterruptHandler) 
        { 
            ADC1_CH_AN12_TEMPLOCALDefaultInterruptHandler(valCH_AN12_TEMPLOCAL); 
        }
    }
}

void __attribute__ ((weak)) ADC1_CH_AN15_VBUS_CallBack( uint16_t adcVal )
{ 

}

void ADC1_SetCH_AN15_VBUSInterruptHandler(void* handler)
{
    ADC1_CH_AN15_VBUSDefaultInterruptHandler = handler;
}

void __attribute__ ((weak)) ADC1_CH_AN15_VBUS_Tasks ( void )
{
    uint16_t valCH_AN15_VBUS;

    if(ADSTATLbits.AN15RDY)
    {
        //Read the ADC value from the ADCBUF
        valCH_AN15_VBUS = ADCBUF15;

        if(ADC1_CH_AN15_VBUSDefaultInterruptHandler) 
        { 
            ADC1_CH_AN15_VBUSDefaultInterruptHandler(valCH_AN15_VBUS); 
        }
    }
}

void __attribute__ ((weak)) ADC1_CH_AN17_VA_CallBack( uint16_t adcVal )
{ 

}

void ADC1_SetCH_AN17_VAInterruptHandler(void* handler)
{
    ADC1_CH_AN17_VADefaultInterruptHandler = handler;
}

void __attribute__ ((weak)) ADC1_CH_AN17_VA_Tasks ( void )
{
    uint16_t valCH_AN17_VA;

    if(ADSTATHbits.AN17RDY)
    {
        //Read the ADC value from the ADCBUF
        valCH_AN17_VA = ADCBUF17;

        if(ADC1_CH_AN17_VADefaultInterruptHandler) 
        { 
            ADC1_CH_AN17_VADefaultInterruptHandler(valCH_AN17_VA); 
        }
    }
}

void __attribute__ ((weak)) ADC1_CH_AN22_VC_CallBack( uint16_t adcVal )
{ 

}

void ADC1_SetCH_AN22_VCInterruptHandler(void* handler)
{
    ADC1_CH_AN22_VCDefaultInterruptHandler = handler;
}

void __attribute__ ((weak)) ADC1_CH_AN22_VC_Tasks ( void )
{
    uint16_t valCH_AN22_VC;

    if(ADSTATHbits.AN22RDY)
    {
        //Read the ADC value from the ADCBUF
        valCH_AN22_VC = ADCBUF22;

        if(ADC1_CH_AN22_VCDefaultInterruptHandler) 
        { 
            ADC1_CH_AN22_VCDefaultInterruptHandler(valCH_AN22_VC); 
        }
    }
}

void __attribute__ ((weak)) ADC1_CH_AN23_VB_CallBack( uint16_t adcVal )
{ 

}

void ADC1_SetCH_AN23_VBInterruptHandler(void* handler)
{
    ADC1_CH_AN23_VBDefaultInterruptHandler = handler;
}

void __attribute__ ((weak)) ADC1_CH_AN23_VB_Tasks ( void )
{
    uint16_t valCH_AN23_VB;

    if(ADSTATHbits.AN23RDY)
    {
        //Read the ADC value from the ADCBUF
        valCH_AN23_VB = ADCBUF23;

        if(ADC1_CH_AN23_VBDefaultInterruptHandler) 
        { 
            ADC1_CH_AN23_VBDefaultInterruptHandler(valCH_AN23_VB); 
        }
    }
}


void __attribute__ ((weak)) ADC1_CH_AN0_IA_CallBack( uint16_t adcVal )
{ 

}

void ADC1_SetCH_AN0_IAInterruptHandler(void* handler)
{
    ADC1_CH_AN0_IADefaultInterruptHandler = handler;
}

void __attribute__ ( ( __interrupt__ , auto_psv, weak ) ) _ADCAN0Interrupt ( void )
{
    uint16_t valCH_AN0_IA;
    //Read the ADC value from the ADCBUF
    valCH_AN0_IA = ADCBUF0;

    if(ADC1_CH_AN0_IADefaultInterruptHandler) 
    { 
        ADC1_CH_AN0_IADefaultInterruptHandler(valCH_AN0_IA); 
    }

    //clear the CH_AN0_IA interrupt flag
    IFS5bits.ADCAN0IF = 0;
}

void __attribute__ ((weak)) ADC1_CH_AN1_IB_CallBack( uint16_t adcVal )
{ 

}

void ADC1_SetCH_AN1_IBInterruptHandler(void* handler)
{
    ADC1_CH_AN1_IBDefaultInterruptHandler = handler;
}

void __attribute__ ((weak)) ADC1_CH_AN1_IB_Tasks ( void )
{
    uint16_t valCH_AN1_IB;

    if(ADSTATLbits.AN1RDY)
    {
        //Read the ADC value from the ADCBUF
        valCH_AN1_IB = ADCBUF1;

        if(ADC1_CH_AN1_IBDefaultInterruptHandler) 
        { 
            ADC1_CH_AN1_IBDefaultInterruptHandler(valCH_AN1_IB); 
        }
    }
}



/**
  End of File
*/
