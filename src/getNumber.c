#include "getNumber.h"
#include <stdio.h>
#include <stdlib.h>

uint32_t getNumber( void )
{
   uint32_t num = 0;
   char ch;
   while( (ch = getchar()) != '\n' )
   {
      if( ( ch == '-' ) || ( ch == '.' ) ||
          ( ( 'A' <= ch ) && ( 'Z' >= ch ) ) ||
          ( ( 'a' <= ch ) && ( 'z' >= ch ) ) )
      {
         printf( "ERROR: Invalid input [%c]. Input must be a non-negative integer\n\r",
                  ch );
         fflush( stdout );
         while( (ch = getchar()) != '\n' );
         return 0;
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
