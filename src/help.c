#include "help.h"
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void help( void )
{
  printf( "Program: Memory Manipulator\n\r" );
  printf( "Commands:\n\r" );
  printf( "'help' - print help menu\n\r" );
  printf( "'quit' - exit program\n\r" );
  printf( "'allocate' - proceed to prompt for number of 32-bit words of memory to allocate\n\r" );
  printf( "'free' - free allocated memory\n\r" );
  printf( "'invert' - invert the state of all bits in specified memory\n\r" );
  printf( "'write' - proceed to prompt for address to write to, followed by value to write\n\r" );

  fflush( stdout );
  return;
}
