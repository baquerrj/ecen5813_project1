/*FileName:getNumberOfWords.h
*Description: This function takes no input but returns a uint32_t representing the number of words
*    of memory to allocate
*Authors: Robert Baquerizo, Vance Farren
*Tools: 
*   Linker: GNU 
*   Compiler: GCC 
*   Debugger: NONE
*Leveraged Code:
*Links:
*/

#ifndef GET_NUMBER_OF_WORDS_H
#define GET_NUMBER_OF_WORDS_H
#include <stdint.h>

/* Genumber of words to allocate memory for
 * Calls getNumber() to read fro stdin */
uint32_t getNumberOfWords( void );

#endif /* GET_NUMBER_OF_WORDS_H */
