/*FileName: verifyMemory.h
*Description: This function verifies that the pseudorandom value written to a specified address
*   is correct.  Inputs are the address as well as the seed value used to populate the contents
*   of that address.  There is no return value
*Authors: Robert Baquerizo, Vance Farren
*Tools: 
*   Linker: GNU 
*   Compiler: GCC 
*   Debugger: NONE
*Leveraged Code:
*Links:
*/

#ifndef VERIFY_MEMORY_H
#define VERIFY_MEMORY_H
#include <stdint.h>

/* Write uint32_t val to memory address
 * pointed to by p_address */
void verifyMemory( void *p_address, uint32_t random );

#endif /* VERIFY_MEMORY_H */
