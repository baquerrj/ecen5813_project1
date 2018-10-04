/*FileName:getNumberOfWords.c
*Description: This function takes no input but returns a uint32_t representing the number of words
*    of memory to allocate
*Authors: Robert Baquerizo, Vance Farren
*Tools: 
*   Linker: GNU 
*   Compiler: GCC 
*   Debugger: NONE
*Leveraged Code:
*Links:
*/

#include "getNumberOfWords.h"
#include "getNumber.h"
#include <stdio.h>

uint32_t getNumberOfWords( void )
{
   uint32_t nWords = 0;
   printf( "How many 32-bit words do you wish to allocate memory for?\n\r");
   fflush( stdout );
   nWords = getNumber();
   if( 0 != nWords )
   {
      printf( "%u words it is!\n\r", nWords );
      fflush( stdout );
   }
  return nWords;
}
