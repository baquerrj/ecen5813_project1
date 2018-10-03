#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/allocate.h"
#include "../inc/help.h"
#include "../inc/getValue.h"
#include "../inc/getAddress.h"
#include "../inc/getNumber.h"
#include "../inc/writeToMemory.h"
#include "../inc/getNumberOfWords.h"
#include "../inc/getRandom.h"
#include "../inc/verifyMemory.h"


#define TRUE 1
#define FALSE 0
#define MAX_INPUT_LENGTH 20

int main( void )
{
  char* p_input = (char*) calloc( MAX_INPUT_LENGTH, sizeof( char* ) );
  uint32_t size = 0;
  uint8_t allocated = 0;
  uint32_t nWords = 0;
  uint32_t value = 0;
  uint8_t doAllocate = 1;
  void* mem = NULL; //Addition of NULL
  uint8_t sizeOfmem = sizeof(mem);
  const uint32_t MAX_UINT32 = 4294967295;
  uint32_t randomSeed = 0;
  uint32_t random = 0;
  //uint8_t seedOnce = 0;//only permit the seeding of the random number generator once

  uint8_t _64bitMachine = FALSE;
  if( sizeOfmem > 4 ) 
  {
     _64bitMachine = TRUE;
  }

  printf("_64bitMachine: %d\n\r", _64bitMachine);

  printf("sizeof mem ptr: %d\n\r", sizeOfmem);

  printf( "Hello and welcome! Enter 'help' for help menu\n\r" );
  fflush( stdout ); 

  while( 1 )
  {
     printf( "> " );
     fflush( stdout );
     if( fgets( p_input, MAX_INPUT_LENGTH, stdin ) != NULL )
     {
        if( 0 == strcmp( "help\n", p_input ) )
        {
           help();
           continue;
        }
        else if( 0 == strcmp( "quit\n", p_input ) )
        {
           if( 1 == allocated )
           {
              printf( "You have not freed memory!\n\r" );
              printf( "Doing your work for you..\n\r" );
              printf( "Freeing %u bytes of memory.\n\r", size );
              fflush( stdout );
              free( mem );
           }
           free( p_input );
           printf( "Exiting...");
           break;
        }
        else if( ( 0 == allocated ) && ( 0 == strcmp( "allocate\n", p_input ) ) )
        {
           nWords = getNumberOfWords();
           if( 1 == doAllocate )
           {
              size = allocate( &mem, nWords );
              allocated = 1;
           }
           else
           {
              printf( "Did not allocate any memory. You probably did bad things...\n\r" );
              fflush( stdout );
              continue;
           }
           // Reset for next attempt
           doAllocate = 1;
           continue;
        }
        else if( ( 1 == allocated ) && ( 0 == strcmp( "free\n", p_input ) ) )
        {
           printf( "Freeing %u byes of memory\n\r", size );
           fflush( stdout );
           free( mem );
           allocated = 0;
           doAllocate = 1;
           continue;
        }
        else if( ( 1 == allocated ) && ( 0 == strcmp( "write\n", p_input ) ) )
        {
           void* currentAddress = mem;
           printf( "You are at address %p\n\r", currentAddress );
           printf( "Input offset to address you'd like to write to\n\r" );
           fflush( stdout );
           uint8_t offset = 0;
           if( ( offset = getNumber() ) > ( size / 4 ) )
           {
              printf( "ERROR: Out of range of allocated memory!\n\r" );
              fflush( stdout );
              continue;
           }

           while( 0 != offset )
           {
              currentAddress += 32;
              offset--;
           }

           /*printf( "What value would you like to write to address %p?\n\r", currentAddress );
           printf( "Input must be in hexadecimal format: " );
           fflush( stdout );
           if( NULL != fgets( p_input, MAX_INPUT_LENGTH, stdin ) )
           {
              value = getValue();
           }
           else
           {
              printf( "ERROR: Could not read from stdin!\n\r" );
              fflush( stdout );
              continue;
           }
           */
           value = getValue();
           writeToMemory( currentAddress, value );

           // Set back to 0 for next attempt
           continue;
        }
        else if( ( 1 == allocated ) && ( 0 == strcmp( "writePattern\n", p_input ) ) )
        {
          void* currentAddress = mem;
           printf( "You are at address %p\n\r", currentAddress );
           printf( "Input offset to address you'd like to write pattern to\n\r" );
           fflush( stdout );
           uint32_t offset = 0;
           if( ( offset = getNumber() ) > ( size / 4 ) )
           {
              printf( "ERROR: Out of range of allocated memory!\n\r" );
              fflush( stdout );
              continue;
           }

           while( 0 != offset )
           {
              currentAddress += 32;
              offset--;
           }

           printf( "Input positive seed value for random number generation\n\r");
           printf( "that fits in a 32 bit unsigned integer\n\r");

           fflush( stdout );

           
           if( ( randomSeed = getNumber() ) > MAX_UINT32 )
           {
              printf( "ERROR: too large!\n\r" );
              fflush( stdout );
              continue;
           }
           random = getRandom(randomSeed);
           writeToMemory( currentAddress, random );

           // Set back to 0 for next attempt
           continue;
        }
        else if( ( 1 == allocated ) && ( 0 == strcmp( "verifyPattern\n", p_input ) ) )
        {
          void* currentAddress = mem;
           printf( "You are at address %p\n\r", currentAddress );
           printf( "Input offset to address at which you'd like to verify pattern\n\r" );
           fflush( stdout );
           uint32_t offset = 0;
           if( ( offset = getNumber() ) > ( size / 4 ) )
           {
              printf( "ERROR: Out of range of allocated memory!\n\r" );
              fflush( stdout );
              continue;
           }

           while( 0 != offset )
           {
              currentAddress += 32;
              offset--;
           }

           printf( "Input positive seed value to verify against random number generation.\n\r");
           printf( "It mush fit in a 32 bit unsigned integer\n\r");

           fflush( stdout );

           if( ( randomSeed = getNumber() ) > MAX_UINT32 )
           {
              printf( "ERROR: too large!\n\r" );
              fflush( stdout );
              continue;
           }
           
           random = getRandom(randomSeed);
           verifyMemory(currentAddress, random);
           //writeToMemory( currentAddress, random );

           // Set back to 0 for next attempt
           continue;
        }
        else
        {
           printf( "Unrecognized command!\n\r" );
           fflush( stdout );
           continue;
        }
     }
     return 1;
  }
  return 1;
}




