#include<avr/io.h>

#include"../inc/Activity2.h"

uint16_t readADC(uint8_t ch);

int Activity2()
{
    /*initializing ADC in controller */
    ADMUX = (1<<REFS0);
    ADCSRA = (1<<ADEN) | (7<<ADPS0);

    /*defining Port B pin 1 as output port*/
    DDRB |= (1<<PB1);

    /*variable to catch ADC value*/
    
    int value = readADC(0);
    /*turn on LED when calue is greater than specidfied limits*/
    if(value > 512)
    {
        PORTB |= (1<<PB1);
    }
    else
    {
        PORTB &= ~(1<<PB1);
    }
    return value;
}

uint16_t readADC(uint8_t ch)
{
    //clearing ADC mux register.
    ADMUX &= 0xf8;
    //decoding the channel number for conversion.
    ch &= 0b00000111;
    ADMUX |= ch;
    /*Start single conversion*/
    ADCSRA |= (1<<ADSC);
    //wait for conversion to end.
    while(!(ADCSRA&(1<<ADIF)));
    //clear ADIF by writing 1 to it/
    ADCSRA |= (1<<ADIF);
    return(ADC);
}

