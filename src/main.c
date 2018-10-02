#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/memoryManipulation.h"

#define TRUE 1
#define FALSE 0

int main( void )
{
  char* p_input = (char*) calloc( MAX_INPUT_LENGTH, sizeof( char* ) );
  uint8_t allocated = 0;
  uint32_t nWords = 0;
  uint32_t value = 0;
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
           nWords = getNumberOfWords();
           if( 1 == doAllocate )
           {
              allocate( &mem, nWords );
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
           if( NULL != fgets( p_input, MAX_INPUT_LENGTH, stdin ) )
           {
              value = getValue();
           }
           else
           {
              printf( "ERROR: Could not read from stdin!\n\r" );
              continue;
           }

           writeToMemory( currentAddress, value );

           // Set back to 0 for next attempt
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

void allocate( void **mem, uint32_t nWords )
{
   size = nWords * sizeof( uint32_t );
   *mem = malloc( size );

   printf( "Allocated %u bytes of memory for %d 32-bit words at adress %p.\n\r",
            size, nWords, *mem );

   return;
}

void help( void )
{
  printf( "Program: Memory Manipulator\n\r" );
  printf( "Commands:\n\r" );
  printf( "'help' - print help menu\n\r" );
  printf( "'quit' - exit program\n\r" );
  printf( "'allocate' - proceed to prompt for number of 32-bit words of memory to allocate\n\r" );
  printf( "'free' - free allocated memory\n\r" );
  printf( "'invert' - invert the state of all bits in specified memory\n\r" );
  printf( "'write' - proceed to prompt for address to write to, followed by value to write\n\r" );

  fflush( stdout );
  return;
}

uint32_t getValue(void)
{
  printf("what is the value that you would like to write to memory.\n\r");
  printf("Must be 32 bit unsigned integer in hex format, or 8 legal characters.\n\r");
  fflush( stdout );
  char valueCharray[8];
  uint8_t incr = 0;
  char ch;
  uint32_t value = 0;
  while( ((ch = getchar()) != '\n') && incr != 8 )
  {
     if( ( '0' < ch && '9' > ch ) ||
         ( 'a' < ch && 'f' > ch ) ||
         ( 'A' < ch && 'F' > ch ) )
    {
      valueCharray[incr] = ch;
      incr++;
    }
    else
    {
       printf("invalid input: legal entries are 0-9, a-f, A-F");
    }
    fflush( stdout );

    value = strtoul(valueCharray, NULL, 16); 
    printf("value: %u \n\r", value);
  }
  return value; 
}

uint64_t getAddress(void)
{
  char addressCharray[16];
  uint8_t incr = 0;
  char ch;
  uint64_t address = 0;
  while( ((ch = getchar()) != '\n') && incr != 16 )
  {
    if( ( '0' < ch && '9' > ch ) ||
        ( 'a' < ch && 'f' > ch ) ||
        ( 'A' < ch && 'F' > ch ) )
    {
      addressCharray[incr] = ch;
      incr++;
    }
    else(printf("invalid input: legal entries are 0-9, a-f, A-F"));
    fflush( stdout );

    address = strtoull(addressCharray, NULL, 16); 
    printf("address: %"PRIu64" \n\r", address);
  }
  return address;
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
         doAllocate = 0;
         break;
      }
      else if( ch == '.' )
      {
         printf( "ERROR: Input must be an integer, not a double.\n\r" );
         fflush( stdout );
         doAllocate = 0;
         break;
      }
      else if( ( ( 'A' <= ch ) && ( 'Z' >= ch ) ) ||
               ( ( 'a' <= ch ) && ( 'z' >= ch ) ) )
      {
         printf( "ERROR: Input must be an integer, not words!\n\r" );
         fflush( stdout );
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
   printf( "Value %u is written to memory adress %p\n\r", *(uint32_t*)p_address, p_address );
   return;
}

uint32_t getNumberOfWords( void )
{
   uint32_t nWords = 0;
   printf( "How many 32-bit words do you wish to allocate memory for?\n\r");
   fflush( stdout );
   nWords = getNumber();
   if( ( 1 == doAllocate ) && ( 0 != nWords ) )
   {
      printf( "%u words it is!\n\r", nWords );
      fflush( stdout );
   }

   return nWords;
}


