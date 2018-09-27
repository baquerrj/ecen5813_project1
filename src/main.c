/*




References:  
https://stackoverflow.com/questions/1398307/how-can-i-allocate-memory-and-return-it-via-a-pointer-parameter-to-the-calling
*/




#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/memoryManipulation.h"

int main( void )
{
  char* p_input = (char*) calloc( MAX_INPUT_LENGTH, sizeof( char* ) );
  uint8_t allocated = 0;
  void* mem = NULL; //Addition of NULL

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
            printf( "Returning to prompt..\n\r" );
            fflush( stdout );
            continue;
          }
            free( p_input );
            printf( "Exiting...");
            fflush( stdout );
            break;
        }
        else if( ( 0 == allocated ) && ( 0 == strcmp( "allocate\n", p_input ) ) )
        {
          uint32_t nWords = getNumberOfWords();
          allocate( &mem, nWords );
          allocated = 1;
          continue;
        }
        else if( ( 1 == allocated ) && ( 0 == strcmp( "free\n", p_input ) ) )
        {
          printf( "Freeing %u byes of memory\n\r", size );
          fflush( stdout );
          free( mem );
          allocated = 0;
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

void allocate( void **mem, uint32_t nWords )
{
  
  size = nWords * sizeof( uint32_t );
  mem = malloc( size );

  printf( "Allocated %u bytes of memory for %d 32-bit words at adress %p.\n\r",
               size, nWords, mem );
  fflush( stdout );
}


void help( void )
{
  printf( "Hello and welcome!\n\r" );
  printf( "This utility allows the user to allocate memory\n\r" );
  printf( "for a specified number of 32-bit words, and do all\n\r" );
  printf( "sorts of cool stuff with the allocated memory.\n\n\r" );
  printf( "For example, you can request to see the contents of a memory address\n\r" );
  printf( "you specify, and the number of 32-bit words to display.\n\r" );
  printf( "You can also write a non-negative value to a memory address.\n\r" );
  printf( "If you just want to mess with the allocated memory, for\n\r" );
  printf( "whatever reason, you can request to invert all memory bits in a\n\r" );
  printf( "specified area of memory, defined by address and number of 32-bit words.\n\r" );
  printf( "If you are not creative enough to think of a value to write to memory,\n\r" );
  printf( "I can write a random pattern to an area of memory you specify, but you\n\r" );
  printf( "must at least be creative enough to provide a seed value for me to work with.\n\r" );
  printf( "If you choose to go the randomly-generated pattern route, and you would then\n\r" );
  printf( "want to verify the pattern written to a specified area of memory, you need only ask.\n\r" );
  fflush( stdout );
  return;
}

uint32_t getNumber( void )
{
  uint32_t num = 0;
  char ch;
  while( (ch = getchar()) != '\n' )
  {
    if( ch == '-' )
    {
      printf( "ERROR: Input cannot be a negative integer.\n\r" );
      fflush( stdout );
      return 0;
    }
    else if( ch == '.' )
    {
      printf( "ERROR: Input must be an integer, not a double.\n\r" );
      fflush( stdout );
      return 0;
    }
    if( '9' < ch || '0' > ch )
    {
      continue;
    }
    num *= 10;
    num += ch - '0';
  }
return num;
}

void writeToMemory( void *p_address, uint32_t val )
{
  printf( "Writing value of %x to memory address\n\r", val );
  fflush( stdout );
  return;
}

uint32_t getNumberOfWords( void )
{
  uint32_t nWords = 0;
  printf( "How many 32-bit words do you wish to allocate memory for?\n\r");
  fflush( stdout );
  nWords = getNumber();
  printf( "%u words it is!\n\r", nWords );
  fflush( stdout );

  return nWords;
}


