/*FileName:getValue.c
*Description: This function gets user input.  Input must be in hex and is
*   the value to be written to memory.
*Authors: Robert Baquerizo, Vance Farren
*Tools: 
*   Linker: GNU 
*   Compiler: GCC 
*   Debugger: NONE
*Leveraged Code:
*Links:
*/

#include "getValue.h"
#include <stdio.h>
#include <stdlib.h>

uint32_t getValue(void)
{
  printf("What is the value that you would like to write to memory.\n\r");
  printf("Must be 32 bit unsigned integer in hex format, or 8 legal characters.\n\r");
  fflush( stdout );
  char valueCharray[8];
  uint8_t incr = 0;
  char ch;
  uint32_t value = 0;
  while( ((ch = getchar()) != '\n') && incr != 8 )
  {
     if( ( '0' <= ch && '9' >= ch ) ||
         ( 'a' <= ch && 'f' >= ch ) ||
         ( 'A' <= ch && 'F' >= ch ) )
    {
      valueCharray[incr] = ch;
      incr++;
    }
    else
    {
       printf("invalid input [%c]: legal entries are 0-9, a-f, A-F\n\r", ch);
       fflush( stdout );
    }
    value = strtoul(valueCharray, NULL, 16); 
  }
  return value; 
}
