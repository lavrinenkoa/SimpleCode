#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>
#include "stdint.h"

#include <execinfo.h>



int main(int argc, char *argv[])
{
    //            1111222233334444 
    uint16_t qos=0b0000000000101001;
    
    int class=0;
    int priority=0;
    int preference=0;
    int hendling=0;
    int requests=0;
    
/*    
    class      = ( qos & 0b0000000000000111);
    priority   = ( qos & 0b0000000000111000) >> 3;
    preference = ( qos & 0b0000000111000000) >> 6;
    hendling   = ( qos & 0b0001111000111000) >> 9;
    requests   = ( qos & 0b1110000000111000) >> 13;
    
    printf("QOS        %d\n", qos);
    printf("class      %d\n", class);
    printf("priority   %d\n", priority);
    printf("preference %d\n", preference);
    printf("hendling   %d\n", hendling);
    printf("requests   %d\n", requests);
*/
    
    priority = 6;
    priority = priority << 3;
    qos = (qos & ~0b0000000000111000) | priority;
    qos &=  (~0b0000000000111000) | priority;
    
    printf("QOS        %d\n", qos);
    //printf("priority   %d\n", priority);

    
    exit(EXIT_SUCCESS);
}
