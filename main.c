#include <avr/io.h>

uint16_t volatile sitting,heater;

int main(void)
{
    DDRD &= ~(1<<PD2); //input pin Port D pin 2
    DDRD &= ~(1<<PD3);  //input pin Port D pin 3

    /*Setting the port at logic HIGH*/
    PORTD |= (1<<PD2);
    PORTD |= (1<<PD3);

    /*SETTIG PORT B PIN 0 AS OUTPUT */
    DDRB |= (1<<PB0);

    while(1)
    {
        //if the value of ADC is above 512, the both condition is considered ON*/
        // For eg. if value of sitting is 600, means the person is sitting in the seat.


        if  ( (!(PIND & (1<<PD2))) & (!(PIND & (1<<PD3))) )
        {
            PORTB |= (1<<PB0);  //TURN ON LED
        }
        else
        {
            PORTB &= ~(1<<PB0);
        }
    }
    return 0;
}

