#ifndef HELPER_H
#define HELPER_H

#define MAX_INPUT_LENGTH 20

/* Size of memory to allocate.
 * calculated in allocate() */
uint32_t size = 0;

/* Signal if input to stdin is in hex format
   0: input is in hex format (false)
   1: input is not in hex format (true) */
uint8_t notHex = 0;

/* Signal if we should allocate memory:
 * 0: prevents allocation
 *    User input to getNumber() from stdin was:
 *      1) negative integer.
 *      2) not a number, e.g. a letter.
 *      3) not an integer, e.g. a float/double.
 * 1: allows allocation */
uint8_t doAllocate = 1;

/* Print help menu */
void help( void );

/* Parse input hex value and returns uint32_t value */
uint32_t parseHex( char* p_hex );

/* Parse input from stdin and returns uint32_t value */
uint32_t getNumber( void );

/* Write uint32_t val to memory address
 * pointed to by p_address */
void writeToMemory( void *p_address, uint32_t val );

/* Genumber of words to allocate memory for
 * Calls getNumber() to read fro stdin */
uint32_t getNumberOfWords( void );

/* Allocate memory for specified number Returns pointer to memory location */
void* allocate( uint32_t nWords );

#endif /* HELPER_H */
