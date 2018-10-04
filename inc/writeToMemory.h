/*FileName: writeToMemory.h
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

#ifndef WRITE_TO_MEMORY_H
#define WRITE_TO_MEMORY_H
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Write uint32_t val to memory address
 * pointed to by p_address */
void writeToMemory( void *p_address, uint32_t val );


#endif /* WRITE_TO_MEMORY_H */
