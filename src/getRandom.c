/*FileName:getRandom.c
*Description: This function takes a uin32_t seed number and returns a pseudorandom result
*Authors: Robert Baquerizo, Vance Farren
*Tools: 
*   Linker: GNU 
*   Compiler: GCC 
*   Debugger: NONE
*Leveraged Code: https://stackoverflow.com/questions/7602919/how-do-i-generate-random-numbers-without-rand-function
*Links: https://en.wikipedia.org/wiki/Linear-feedback_shift_register
*/


/*
number of taps must be even
set of taps must be co-prime
will use taps at positions 23 and 18
32-23 = 9
32-18 = 14
*/

#include "getRandom.h"

uint32_t getRandom( uint32_t randomSeed )
{
   uint32_t bit;

   bit  = ((randomSeed >> 9) ^ (randomSeed >> 14) ) & 1;
   return randomSeed =  (randomSeed >> 1) | (bit << 31);
}
