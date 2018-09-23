#ifndef HELPER_H
#define HELPER_H

#define MAX_INPUT_LENGTH 20

uint32_t size = 0;
// Print help menu
void help( void );

// Get unsigned integer from stdin
uint32_t getNumber( void );

// Write usigned integer vall to memory address
// pointed to by p_address
void writeToMemory( void *p_address, uint32_t val );

// Get number of 32-bit bit words. Calls getNumber()
uint32_t getNumberOfWords( void );

// Allocate memory for specified number
// 32-bit words. Returns pointer to memory location
void* allocate( uint32_t nWords );

#endif /* HELPER_H */
