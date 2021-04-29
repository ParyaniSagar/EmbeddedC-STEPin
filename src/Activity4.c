//#include<Activity4.h>
#include<avr/io.h>
#include<string.h>

#define BAUD 9600
#define F_CPU 16000000
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)

void USART_init()
{
    /*PD0 RXD PD1 TXD*/
    
    /*sET BAUD RATE TO REGISTER*/
    UBRR0H = (BAUDRATE>>8);
    UBRR0L = BAUDRATE;
    
    /*SETTING SYNCHRONOUS COMMUNICATION OF 8 BIT TRANSCIEVER*/
    UCSR0C = (1<<UMSEL00) | (1<<UCSZ01) | (1<<UCSZ00);

    /*ENABLE THE RECIEVER AND TRANSIMTTER*/
    UCSR0B = (1<<RXEN0) | (1<<TXEN0) | (1<<RXCIE0) | (1<<TXCIE0);
}

/*Program to read the value coming thru any otehr peripheral*/
char USART_read()
{
    while( !(UCSR0A & (1<<RXC0)) );
    return UDR0;
}

/*Program to write to other peripheral using UART*/
void USART_write(char data)
{
    while( !(UCSR0A & (1<<UDRE0)) );
    UDR0 = data;
}

/*To write a string data using a loop*/
void write_string(char *string)
{
    int count;
    int len_string = strlen(string);
    for(count = 0 ; count < len_string; count++)
    {
        USART_write(*(string+count));
    }
}


void Activity4(char *data)
{
  
    USART_init();
    write_string(data);
}

