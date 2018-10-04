/*FileName: allocate.h
*Description: This header file contains the prototype for the allocate function which:
*   takes the initial allocated memory address and number of words as input and
*   returns the size of the input
*Authors: Robert Baquerizo, Vance Farren
*Tools: 
*   Linker: GNU 
*   Compiler: GCC 
*   Debugger: NONE
*Leveraged Code:
*Links:
*/

#ifndef ALLOCATE_H
#define ALLOCATE_H
#include <stdint.h>
#include <stdlib.h>

/* Allocate memory for specified number Returns pointer to memory location */
uint32_t allocate( void **mem, uint32_t nWords );

#endif /* ALLOCATE_H */
