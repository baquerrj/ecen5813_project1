#include "verifyMemory.h"
#include <stdio.h>

void verifyMemory( void *p_address, uint32_t random )
{
   if(*((uint32_t*)p_address) == random)
   {
       printf("random value is equal to that found at the selected memory address\n\r");
   }
   else 
   {
       printf("random value is not equal to that found at the selected memory address\n\r");
       printf("expected random value: %x\n\r ",random );
       printf("actual value is: %x\n\r ",*((uint32_t*)p_address));
       printf("memory address of discrepancy: %p\n\r", p_address);
   }
   return;
}
