#include <Activity1.h>
#include <Activity3.h>
#include<avr/io.h>

int main(void)
{
    while(1)
    {
        /*Activity 1,2,4 are called in Activity 3*/
        Activity3();
    }
    return 0;
}