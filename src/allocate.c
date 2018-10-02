#include "../inc/allocate.h"
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


uint32_t allocate( void **mem, uint32_t nWords )
{
   uint32_t size = nWords * sizeof( uint32_t );
   *mem = malloc( size );

   printf( "Allocated %u bytes of memory for %d 32-bit words at adress %p.\n\r",
            size, nWords, *mem );

   return size;
}