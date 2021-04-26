#include <avr/io.h>

#include"./inc/port_init.h"

int main(void)
{

    port_init();

    while(1)
    {

        if  ( (!(PIND & (1<<PD2))) & (!(PIND & (1<<PD3))) )
        {
            PORTB |= (1<<PB0);  //TURN ON LED
        }
        else
        {
            PORTB &= ~(1<<PB0); //TURN OFF LED
        }
    }
    return 0;
}

