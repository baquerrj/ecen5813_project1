#ifndef ALLOCATE_H
#define ALLOCATE_H
#include <stdint.h>
#include <stdlib.h>

/* Allocate memory for specified number Returns pointer to memory location */
uint32_t allocate( void **mem, uint32_t nWords );

#endif /* ALLOCATE_H */
