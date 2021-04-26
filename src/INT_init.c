#include <INT_init.h>
#include <avr/io.h>



void INT_init(void)
{
    /*Resetting External Interrupt Control Register A setting*/
    EICRA = 0x00;

    /*The falling edge of INT1 & INT0 generates an interrupt request */
    EICRA = (1<<ISC11) | (1<<ISC01);   

    /*Set the Mask register. */
    EIMSK = (1<<INT1) | (1<<INT0);     

}