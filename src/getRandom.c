#include "getRandom.h"
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//SOURCE: https://stackoverflow.com/questions/7602919/how-do-i-generate-random-numbers-without-rand-function
//https://en.wikipedia.org/wiki/Linear-feedback_shift_register
/*
number of taps must be even
set of taps must be co-prime
will use taps at positions 23 and 18
32-23 = 9
32-18 = 14


*/
uint32_t getRandom( uint32_t randomSeed )
{
    uint32_t bit;

    bit  = ((randomSeed >> 9) ^ (randomSeed >> 14) ) & 1;
    return randomSeed =  (randomSeed >> 1) | (bit << 31);
 
}
