#include<avr/io.h>

#include"../inc/port_init.h"

void port_init()
{
    DDRD &= ~(1<<PD2); //input pin Port D pin 2
    DDRD &= ~(1<<PD3);  //input pin Port D pin 3

    /*Setting the port at logic HIGH*/
    PORTD |= (1<<PD2);
    PORTD |= (1<<PD3);

    /*SETTIG PORT B PIN 0 AS OUTPUT */
    DDRB |= (1<<PB0);
}
