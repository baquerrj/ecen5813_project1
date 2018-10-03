#ifndef VERIFY_MEMORY_H
#define VERIFY_MEMORY_H
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* Write uint32_t val to memory address
 * pointed to by p_address */
void verifyMemory( void *p_address, uint32_t random );




#endif /* VERIFY_MEMORY_H */