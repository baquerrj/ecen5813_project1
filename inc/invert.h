#ifndef INVERT_H
#define INVERT_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define ANDMASK 0xFFFFFFFF
#define XORMASK 0xFFFFFFFF

/* Invert all bits in a memory address */
void invert( void *p_address );


#endif /* INVERT_H */
