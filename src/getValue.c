#include "getValue.h"
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

uint32_t getValue(void)
{
  printf("what is the value that you would like to write to memory.\n\r");
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
