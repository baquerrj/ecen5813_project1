#include "../inc/getAddress.h"
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


uint64_t getAddress(void)
{
  char addressCharray[16];
  uint8_t incr = 0;
  char ch;
  uint64_t address = 0;
  while( ((ch = getchar()) != '\n') && incr != 16 )
  {
    if( ( '0' < ch && '9' > ch ) ||
        ( 'a' < ch && 'f' > ch ) ||
        ( 'A' < ch && 'F' > ch ) )
    {
      addressCharray[incr] = ch;
      incr++;
    }
    else(printf("invalid input: legal entries are 0-9, a-f, A-F"));
    fflush( stdout );

    address = strtoull(addressCharray, NULL, 16); 
    printf("address: %"PRIu64" \n\r", address);
  }
  return address;
}