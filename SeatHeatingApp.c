#include <Activity1.h>
#include <Activity2.h>
#include <Activity3.h>
#include<avr/io.h>

int main(void)
{
    while(1)
    {
        Activity1();
        /*Activity2 AND is used in Activity3*/
        Activity3();
    }
    return 0;
}