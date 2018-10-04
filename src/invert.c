#include "invert.h"
#include <stdio.h>
#include <stdint.h>

void invert( void *p_address )
{
   printf( "Original value at memory address %p is 0x%08x or %08u\n\r",
            p_address, *(uint32_t*)p_address, *(uint32_t*)p_address );

   // Use an AND XOR Mask to flip all bits
   *(uint32_t*)p_address &= ANDMASK;
   *(uint32_t*)p_address ^= XORMASK;


   printf( "After inversion, value at memory address %p is 0x%08x or %08u\n\r",
            p_address, *(uint32_t*)p_address, *(uint32_t*)p_address );

   return;
}

