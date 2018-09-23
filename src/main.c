#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/helper.h"
//#include "helper.h"
int main( void )
{
   //char* p_input[MAX_INPUT_LENGTH];
   char* p_input = (char*) calloc( MAX_INPUT_LENGTH, sizeof( char* ) );
   int firstTime = 0;
   int allocated = 0;
   void* mem;
   while( 1 )
   {
      if( 0 == firstTime )
      {
         printf( "Hello and welcome! Enter 'help' for help menu\n" );
         firstTime++;
      }
      printf( "> " );

      if( fgets( p_input, MAX_INPUT_LENGTH, stdin ) != NULL )
      {
         if( 0 == strcmp( "help\n", p_input ) )
         {
            help();
            continue;
         }
         else if( 0 == strcmp( "quit\n", p_input ) )
         {
            printf( "Exiting...");
            break;
         }
         else if( ( 0 == allocated ) && ( 0 == strcmp( "allocate\n", p_input ) ) )
         {
            //printf( "How many 32-bit words should I allocate memory for?\n" );
            uint32_t nWords = getNumberOfWords();
            mem = allocate( nWords );
            allocated = 1;
            continue;
         }
         else if( ( 1 == allocated ) && ( 0 == strcmp( "free\n", p_input ) ) )
         {
            printf( "Freeing %u byes of memory\n", size );
            free( mem );
            allocated = 0;
            continue;
         }
         else
         {
            printf( "Unrecognized command!\n" );
            continue;
         }
      }

      return 1;
   }
   return 1;
}

void* allocate( uint32_t nWords )
{
   char *mem;
   size = nWords * sizeof( uint32_t );
   mem = (char *)malloc( size );

   printf( "Allocated %u bytes of memory for %d 32-bit words at adress %p.\n",
               size, nWords, (void*)mem );

   return (void*) mem;
}


void help( void )
{
   printf( "Hello and welcome!\n" );
   printf( "This utility allows the user to allocate memory\n" );
   printf( "for a specified number of 32-bit words, and do all\n" );
   printf( "sorts of cool stuff with the allocated memory.\n\n" );
   printf( "For example, you can request to see the contents of a memory address\n" );
   printf( "you specify, and the number of 32-bit words to display.\n" );
   printf( "You can also write a non-negative value to a memory address.\n" );
   printf( "If you just want to mess with the allocated memory, for\n" );
   printf( "whatever reason, you can request to invert all memory bits in a\n" );
   printf( "specified area of memory, defined by address and number of 32-bit words.\n" );
   printf( "If you are not creative enough to think of a value to write to memory,\n" );
   printf( "I can write a random pattern to an area of memory you specify, but you\n" );
   printf( "must at least be creative enough to provide a seed value for me to work with.\n" );
   printf( "If you choose to go the randomly-generated pattern route, and you would then\n" );
   printf( "want to verify the pattern written to a specified area of memory, you need only ask.\n" );
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
         printf( "ERROR: Input cannot be a negative integer.\n" );
         return 0;
      }
      else if( ch == '.' )
      {
         printf( "ERROR: Input must be an integer, not a double.\n" );
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
   printf( "Writing value of %x to memory address\n", val );
   return;
}
uint32_t getNumberOfWords( void )
{
   uint32_t nWords = 0;
   printf( "How many 32-bit words do you wish to allocate memory for?\n ");
   nWords = getNumber();
   printf( "%u words it is!\n", nWords );

   return nWords;
}


