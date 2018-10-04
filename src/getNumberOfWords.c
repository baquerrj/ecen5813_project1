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
