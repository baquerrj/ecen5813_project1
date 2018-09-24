#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/helper.h"

int main( void )
{
   char* p_input = (char*) calloc( MAX_INPUT_LENGTH, sizeof( char* ) );
   uint8_t firstTime = 1;
   uint8_t allocated = 0;
   void* mem;
   if( 1 == firstTime )
   {
      printf( "Hello and welcome! Enter 'help' for help menu\n\r" );
      firstTime--;
   }

   while( 1 )
   {
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
            if( 1 == allocated )
            {
               printf( "You have not freed memory!\n\r" );
               printf( "Doing your work for you..\n\r" );
               printf( "Freeing %u bytes of memory.\n\r", size );
               free( mem );
            }
            free( p_input );
            printf( "Exiting...");
            break;
         }
         else if( ( 0 == allocated ) && ( 0 == strcmp( "allocate\n", p_input ) ) )
         {
            uint32_t nWords = getNumberOfWords();
            if( 1 == doAllocate )
            {
               mem = allocate( nWords );
               allocated = 1;
            }
            else
            {
               printf( "Did not allocate any memory. You probably did bad things...\n\r" );
               continue;
            }
            // Reset for next attempt
            doAllocate = 1;
            continue;
         }
         else if( ( 1 == allocated ) && ( 0 == strcmp( "free\n", p_input ) ) )
         {
            printf( "Freeing %u byes of memory\n\r", size );
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
            uint8_t offset = 0;
            if( ( offset = getNumber() ) > ( size / 4 ) )
            {
               printf( "ERROR: Out of range of allocated memory!\n\r" );
               continue;
            }

            while( 0 != offset )
            {
               currentAddress++;
               offset--;
            }

            printf( "What value would you like to write to address %p?\n\r", currentAddress );
            printf( "Input must be in hexadecimal format: " );
            uint32_t value = 0;
            if( NULL != fgets( p_input, MAX_INPUT_LENGTH, stdin ) )
            {
               value = parseHex( p_input );
            }
            else
            {
               printf( "ERROR: Could not read from stdin!\n\r" );
               continue;
            }
            if( 0 == notHex )
            {
               writeToMemory( currentAddress, value );
            }

            // Set back to 0 for next attempt
            notHex = 0;
            continue;
         }
         else
         {
            printf( "Unrecognized command!\n\r" );
            continue;
         }
      }
      return 1;
   }
   return 1;
}

void* allocate( uint32_t nWords )
{
   void* mem;
   size = nWords * sizeof( uint32_t );
   mem = malloc( size );

   printf( "Allocated %u bytes of memory for %d 32-bit words at adress %p.\n\r",
            size, nWords, mem );

   return mem;
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
   return;
}

uint32_t parseHex(char* p_hex )
{
   uint32_t num = 0;
   uint8_t checked = 0;
   uint8_t byte;
   {
      while( '\n' != *p_hex )
      {
         if( 0 == checked )
         {
            checked = 1;
            if( '0' == *p_hex )
            {
               if( '\n' != *p_hex++ )
               {
                  if( 'x' == *p_hex )
                  {
                     p_hex++;
                     continue;
                  }
                  else
                  {
                     printf( "ERROR: Input is not in hexadecimal format!\n\r" );
                     notHex = 1;
                     break;
                  }
               }
               else
               {
                  printf( "ERROR: Unexpected end of line!\n\r" );
                  notHex = 1;
                  break;
               }
            }
            else
            {
               printf( "ERROR: Input is not in hexadecimal format!\n\r" );
               notHex = 1;
               break;
            }
         }
         else if( ( 1 == checked ) && ( 0 == notHex ) )
         {
            byte = *p_hex;
            if( ( '0' <= byte ) && ( '9' >= byte ) )
            {
               byte = byte - '0';
            }
            else if( ( 'a' <= byte ) && ( 'f' >= byte ) )
            {
               byte = byte + 10 - 'a';
            }
            else if( ( 'A' <= byte ) && ( 'F' >= byte ) )
            {
               byte = byte + 10 - 'A';
            }
            num = ( num << 4 ) | ( byte & 0xF );
            p_hex++;
         }
      }
   }
   return num;
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
         doAllocate = 0;
         break;
      }
      else if( ch == '.' )
      {
         printf( "ERROR: Input must be an integer, not a double.\n\r" );
         doAllocate = 0;
         break;
      }
      else if( ( ( 'A' <= ch ) && ( 'Z' >= ch ) ) ||
               ( ( 'a' <= ch ) && ( 'z' >= ch ) ) )
      {
         printf( "ERROR: Input must be an integer, not words!\n\r" );
         doAllocate = 0;
         break;
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
   *((uint32_t*)p_address) = val;
   printf( "Writing value of 0x%x or %u to memory address %p\n\r", val, val, p_address );
   return;
}

uint32_t getNumberOfWords( void )
{
   uint32_t nWords = 0;
   printf( "How many 32-bit words do you wish to allocate memory for?\n\r");
   nWords = getNumber();
   if( ( 1 == doAllocate ) && ( 0 != nWords ) )
   {
      printf( "%u words it is!\n\r", nWords );
   }

   return nWords;
}


