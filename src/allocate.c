/*FileName: allocate.c
*Description: This header file contains the prototype for the allocate function which:
*   takes the initial allocated memory address and number of words as input and
*   returns the size of the input
*Authors: Robert Baquerizo, Vance Farren
*Tools: 
*   Linker: GNU 
*   Compiler: GCC 
*   Debugger: NONE
*Leveraged Code:
*Links:
*/

#include "allocate.h"
#include <stdio.h>


uint32_t allocate( void **mem, uint32_t nWords )
{
   uint32_t size = nWords * sizeof( uint32_t );
   *mem = malloc( size );
   
   if( NULL == *mem )
   {
      printf( "ERROR: Could not allocate memory!\n\r" );
      fflush( stdout );
   }
   else
   {
      printf( "Allocated %u bytes of memory for %d 32-bit words at adress %p.\n\r",
               size, nWords, *mem );
      fflush( stdout );
   }

   return size;
}
