/*FileName:help.c
*Description: This function prints the help menu. There is no input nor return value.
*Authors: Robert Baquerizo, Vance Farren
*Tools: 
*   Linker: GNU 
*   Compiler: GCC 
*   Debugger: NONE
*Leveraged Code:
*Links:
*/

#include "help.h"
#include <stdio.h>

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
  printf( "'writePattern' - proceed to prompt for offset to address to write to,");
  printf("followed by seed value for random number generator \n\r" );
  printf( "'verifyPattern' - proceed to prompt for offset to address to access,"); 
  printf( "followed by seed value to verify against memory contents\n\r" );

  fflush( stdout );
  return;
}
