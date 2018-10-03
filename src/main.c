#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "allocate.h"
#include "help.h"
#include "getValue.h"
#include "getAddress.h"
#include "getNumber.h"
#include "writeToMemory.h"
#include "getNumberOfWords.h"
#include "invert.h"

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
              ( 0 < size ) ? ( allocated = 1 ) : ( allocated = 0 );
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
           uint32_t offset = getNumber();
           if( (nWords-1) < offset )
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

           value = getValue();
           writeToMemory( currentAddress, value );

           continue;
        }
        else if( ( 1 == allocated ) && ( 0 == strcmp( "invert\n", p_input ) ) )
        {
           void* currentAddress = mem;
           printf( "Specify number of 32-bit words to invert\n\r> " );
           fflush( stdout );
           uint32_t offset = getNumber();
           if( nWords < offset )
           {
              printf( "ERROR: Input is larger than number of words allocated!\n\r" );
              fflush( stdout );
              continue;
           }
           if( 0 == offset )
           {
              printf( "ERROR: Input must be a positive integer!\n\r" );
              fflush( stdout );
           }
           while( 0 != offset )
           {
              invert( currentAddress );
              currentAddress += 32;
              offset--;
           }
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




