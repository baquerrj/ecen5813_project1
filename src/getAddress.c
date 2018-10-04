/*FileName:getAddress.c
*Description: This function returns a 64 bit address to be compatible on any system
*Authors: Robert Baquerizo, Vance Farren
*Tools: 
*   Linker: GNU 
*   Compiler: GCC 
*   Debugger: NONE
*Leveraged Code:
*Links:
*/

#include "getAddress.h"
#include <stdlib.h>
#include <stdio.h>

uint64_t getAddress(void)
{
  char addressCharray[16];
  uint8_t incr = 0;
  char ch;
  uint64_t address = 0;
  while( ((ch = getchar()) != '\n') && incr != 16 )
  {
    if( ( '0' <= ch && '9' >= ch ) ||
        ( 'a' <= ch && 'f' >= ch ) ||
        ( 'A' <= ch && 'F' >= ch ) )
    {
      addressCharray[incr] = ch;
      incr++;
    }
    else
    {
       printf( "Invalid input [%c]: legal entries are 0-9, a-f, A-F\n\r", ch );
       fflush( stdout );
    }
    address = strtoull(addressCharray, NULL, 16); 
  }
  return address;
}
