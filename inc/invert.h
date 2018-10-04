/*FileName: invert.h
*Description: This function inverts the contents stored at a specified address.
*   Input is the address. There is no return value
*Authors: Robert Baquerizo, Vance Farren
*Tools: 
*   Linker: GNU 
*   Compiler: GCC 
*   Debugger: NONE
*Leveraged Code:
*Links:
*/

#ifndef INVERT_H
#define INVERT_H

#define ANDMASK 0xFFFFFFFF
#define XORMASK 0xFFFFFFFF

/* Invert all bits in a memory address */
void invert( void *p_address );

#endif /* INVERT_H */
