#include<avr/io.h>

#include"../inc/Activity1.h"

void Activity1()
{
    DDRD &= ~(1<<PD2); //input pin Port D pin 2
    DDRD &= ~(1<<PD3);  //input pin Port D pin 3

    /*Setting the port at logic HIGH*/
    PORTD |= (1<<PD2);
    PORTD |= (1<<PD3);

    /*SETTIG PORT B PIN 0 AS OUTPUT */
    DDRB |= (1<<PB0);

    if  ( (!(PIND & (1<<PD2))) & (!(PIND & (1<<PD3))) )
    {
        PORTB |= (1<<PB0);   //TURN ON LED
    }
    else
    {
       PORTB &= ~(1<<PB0);  //TURN OFF LED
    }
}

