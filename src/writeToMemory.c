/*FileName: writeToMemory.c
*Description:  This function writes a value to specified address.
*   Inputs are the address to write to and the value to be written to the address
*   There is no return value.
*Authors: Robert Baquerizo, Vance Farren
*Tools: 
*   Linker: GNU 
*   Compiler: GCC 
*   Debugger: NONE
*Leveraged Code:
*Links:
*/


#include "writeToMemory.h"


void writeToMemory( void *p_address, uint32_t val )
{
   *((uint32_t*)p_address) = val;
   printf( "Writing value of 0x%x or %u to memory address %p\n\r", val, val, p_address );
   printf( "Value %u is written to memory adress %p\n\r", *(uint32_t*)p_address, p_address );
   return;
}
