#include<avr/io.h>

#include"../inc/Activity2.h"
#include"../inc/Activity3.h"
#include"../inc/Activity4.h"

void Activity3()
{
    unsigned volatile int ADC_val;
    /*Initialize the Timer peripherals*/ 
    /*PD5 and PD6 are two channels for Timer0*/ 
    
    //led initialise
    DDRD |= (1<<PD6);
    
    /*Timer0 control register A*/
    //non-inverting mode(COM0), Fast PWM(WGM)
    TCCR0A |= (1<<COM0A1) | (1<<WGM01) |(1<<WGM00);

    /*Timer0 control register B*/
    //prescalar: 64, Fclk = 16 MHZ.
    TCCR0B |= (1<<CS01) | (1<<CS00);

    TCNT0 = 0;
    while (1)
    {
        
        ADC_val = Activity2();
        if(ADC_val > 0 && ADC_val <= 200)
        {
            OCR0A = 51;
            Activity4("Fifty One\n");
        }
        else if(ADC_val > 210 && ADC_val <= 500)
        {
            OCR0A = 102;
            Activity4("One Hundred Two\n");
        }
        else if(ADC_val > 510 && ADC_val <= 700)
        {
            OCR0A = 180;  
            Activity4("One Hundred Eighty\n"); 
        }
        else if(ADC_val > 710 && ADC_val <= 1024)
        {
            OCR0A = 250;
            Activity4("Two Hundred Fifty\n");
        }
        
    }
}
