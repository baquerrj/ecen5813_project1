/*FileName: main.c
*Description:  This is the entrance to the program.  It takes no inputs and returns 0.
*Authors: Robert Baquerizo, Vance Farren
*Tools: 
*   Linker: GNU 
*   Compiler: GCC 
*   Debugger: NONE
*Leveraged Code:
*Links:
*/

#include "allocate.h"
#include "help.h"
#include "getValue.h"
#include "getAddress.h"
#include "getNumber.h"
#include "writeToMemory.h"
#include "getNumberOfWords.h"
#include "verifyMemory.h"
#include "getRandom.h"
#include "invert.h"
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX_INPUT_LENGTH 20

int main( void )
{
   char* p_input = (char*) calloc( MAX_INPUT_LENGTH, sizeof( char* ) );
   uint32_t size = 0;
   uint8_t allocated = FALSE;
   uint32_t nWords = 0;
   uint32_t value = 0;
   void* mem = NULL;
   uint32_t randomSeed = 0;
   uint32_t random = 0;

   /* For calculating time taken to perform operations */
   clock_t start, end;
   double delta;
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
            if( TRUE == allocated )
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
         else if( 0 == strcmp( "allocate\n", p_input ) )
         {
            if( FALSE == allocated )
            {
               nWords = getNumberOfWords();
               if( 0 != nWords )
               {
                  size = allocate( &mem, nWords );
                  ( 0 < size ) ? ( allocated = TRUE ) : ( allocated = FALSE );
               }
               else
               {
                  printf( "Did not allocate any memory. You probably did bad things...\n\r >" );
                  fflush( stdout );
                  continue;
               }
            }
            else
            {
               printf( "You already allocated memory!\n\r");
               fflush( stdout );
            }
            continue;
         }
         else if( ( TRUE == allocated ) && ( 0 == strcmp( "free\n", p_input ) ) )
         {
            printf( "Freeing %u byes of memory\n\r", size );
            fflush( stdout );
            free( mem );
            allocated = FALSE;
            continue;
         }
         else if( ( TRUE == allocated ) && ( 0 == strcmp( "write\n", p_input ) ) )
         {
            void* currentAddress = mem;
            uint32_t offset = 0;
            printf( "You are at address %p\n\r", currentAddress );
            printf( "Write to specific address, or by offset? Y/N\n\r> ");
            fflush( stdout );

            if( NULL != fgets( p_input, MAX_INPUT_LENGTH, stdin ) )
            {
               if( 0 == strcmp( "Y\n", p_input ) )
               {
                  printf( "Enter hexadecimal address to write to\n\r> " );
                  fflush( stdout);
                  uint64_t address = getAddress();
                  if( ( ( (uint64_t)mem + (32*(nWords-1) ) ) < address ) || 
                      ( (uint64_t)mem > address ) ||
                      ( 0 != ( address - (uint64_t)mem ) % 32 ) )
                  {
                     printf( "ERROR: Out of range of allocated memory!\n\r" );
                     fflush( stdout );
                     continue;
                  }
                  offset = ( address - (uint64_t)mem )/ 32;
               }
               else
               {
                  printf( "Input offset to address you'd like to write to\n\r" );
                  fflush( stdout );
                  offset = getNumber();
                  if( (nWords-1) < offset )
                  {
                     printf( "ERROR: Out of range of allocated memory!\n\r" );
                     fflush( stdout );
                     continue;
                  }
               }
               while( 0 != offset )
               {
                  currentAddress += 32;
                  offset--;
               }
            }

            value = getValue();
            writeToMemory( currentAddress, value );

            continue;
         }
         else if( ( TRUE == allocated ) && ( 0 == strcmp( "invert\n", p_input ) ) )
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

            start = clock();
            while( 0 != offset )
            {
               invert( currentAddress );
               currentAddress += 32;
               offset--;
            }
            end = clock();

            delta = (double)( end - start ) / CLOCKS_PER_SEC;
            printf( "Invert operation took %f seconds\n\r", delta );
            continue;
         }
         else if( ( TRUE == allocated ) && ( 0 == strcmp( "writePattern\n", p_input ) ) )
         {
            void* currentAddress = mem;
            printf( "You are at address %p\n\r", currentAddress );
            printf( "Input offset to address you'd like to write pattern to\n\r> " );
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

            printf( "Input positive seed value for random number generation\n\r");
            printf( "Input must fit in a 32 bit unsigned integer\n\r> ");

            fflush( stdout );

            if( ( randomSeed = getNumber() ) > UINT32_MAX )
            {
               printf( "ERROR: too large!\n\r" );
               fflush( stdout );
               continue;
            }

            start = clock();
            random = getRandom(randomSeed);
            writeToMemory( currentAddress, random );
            end = clock();

            delta = (double)( end - start ) / CLOCKS_PER_SEC;
            printf( "Write pattern operation took %f seconds\n\r", delta );
            continue;
         }
         else if( ( TRUE == allocated ) && ( 0 == strcmp( "verifyPattern\n", p_input ) ) )
         {
            void* currentAddress = mem;
            printf( "You are at address %p\n\r", currentAddress );
            printf( "Input offset to address at which you'd like to verify pattern\n\r> " );
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

            printf( "Input positive seed value to verify against random number generation.\n\r");
            printf( "It must fit in a 32 bit unsigned integer\n\r> ");

            fflush( stdout );

            if( ( randomSeed = getNumber() ) > UINT32_MAX )
            {
               printf( "ERROR: too large!\n\r" );
               fflush( stdout );
               continue;
            }

            start = clock();
            random = getRandom(randomSeed);
            verifyMemory(currentAddress, random);
            end = clock();

            delta = (double)( end - start ) / CLOCKS_PER_SEC;
            printf( "Verify pattern operation took %f seconds\n\r", delta );
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




