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