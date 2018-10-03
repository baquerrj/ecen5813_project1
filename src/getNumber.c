#include "getNumber.h"
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



uint32_t getNumber( void )
{
   uint32_t num = 0;
   char ch;
   while( (ch = getchar()) != '\n' )
   {
      if( ch == '-' )
      {
         printf( "ERROR: Input cannot be a negative integer.\n\r" );
         fflush( stdout );
         //doAllocate = 0;
         break;
      }
      else if( ch == '.' )
      {
         printf( "ERROR: Input must be an integer, not a double.\n\r" );
         fflush( stdout );
         //doAllocate = 0;
         break;
      }
      else if( ( ( 'A' <= ch ) && ( 'Z' >= ch ) ) ||
               ( ( 'a' <= ch ) && ( 'z' >= ch ) ) )
      {
         printf( "ERROR: Input must be an integer, not words!\n\r" );
         fflush( stdout );
         //doAllocate = 0;
         break;
      }
      if( '9' < ch || '0' > ch )
      {
         continue;
      }
      num *= 10;
      num += ch - '0';
   }
   return num;
}
