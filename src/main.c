/*




References:  
https://stackoverflow.com/questions/1398307/how-can-i-allocate-memory-and-return-it-via-a-pointer-parameter-to-the-calling
http://www.cplusplus.com/reference/cstdlib/strtoull/
*/




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
  volatile uint32_t value = 0;
  void* mem = NULL; //Addition of NULL
  uint8_t sizeOfmem = sizeof(mem);
  
  uint8_t _64bitMachine = FALSE;
  if (sizeOfmem > 4) _64bitMachine = TRUE;
  uint64_t address = 0;

  printf("_64bitMachine: %d\n\r", _64bitMachine);

  printf("sizeof mem ptr: %d\n\r", sizeOfmem);
  uint32_t nWords = 0;

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
          nWords = getNumberOfWords();
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
        else if( ( 1 == allocated ) && ( 0 == strcmp( "write\n", p_input ) ) )
        {
          value = getValue();
          printf("value: %u,\n\r", value);
          printf("enter hexadecimal address to write to\n\r");
          fflush( stdout );
          address = getAddress();
          printf("address: %"PRIu64",\n\r", address);
          //if(address > (uint64_t)(*mem+(32*(nWords-1))))
          //{
          //    printf("address too high.  must be between the beginning\n\r");
          //    printf("of allocated space and 32 bits less the end of allocated space\n\r")
          //    fflush(stdout);
          //    continue
          //}else
          //  {
          //    writeaddress()
          //  }
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

uint32_t getValue(void)
{
  printf("what is the value that you would like to write to memory.\n\r");
  printf("Must be 32 bit unsigned integer in hex format, or 8 legal characters.\n\r");
  fflush( stdout );
  char valueCharray[8];
  uint8_t incr = 0;
  char ch;
  uint32_t value = 0;
  while( ((ch = getchar()) != '\n')&& incr != 8 )
  {
    
    if( ('0' < ch || '9' > ch)||('a' < ch || 'f' > ch)||('A' < ch || 'F' > ch) )
    {
      valueCharray[incr] = ch;
      printf("addr[%d]: %c\n\r", incr, valueCharray[incr]);
      fflush( stdout );
      incr++;
    }
    else(printf("invalid input: legal entries are 0-9, a-f, A-F"));
    fflush( stdout );

    value = strtoul(valueCharray, NULL, 16); 
    //sscanf(valueCharray, "%u", &value);
    printf("value: %u \n\r", value);
    //return value; 

    //i = atoi (num);
  }
      return value; 

}

uint64_t getAddress(void)
{
  
  
  char addressCharray[16];
  uint8_t incr = 0;
  char ch;
  uint64_t address = 0;
  while( ((ch = getchar()) != '\n')&& incr != 16 )
  {
    
    if( ('0' < ch || '9' > ch)||('a' < ch || 'f' > ch)||('A' < ch || 'F' > ch) )
    {
      addressCharray[incr] = ch;
      printf("addr[%d]: %c\n\r", incr, addressCharray[incr]);
      fflush( stdout );
      incr++;
    }
    else(printf("invalid input: legal entries are 0-9, a-f, A-F"));
    fflush( stdout );

    address = strtoull(addressCharray, NULL, 16); 
    //sscanf(valueCharray, "%u", &value);
    printf("address: %"PRIu64" \n\r", address);
    //return value; 

    //i = atoi (num);
  }
      return address; 

}

void allocate( void **mem, uint32_t nWords )
{
  
  size = nWords * sizeof( uint32_t );
  *mem = malloc( nWords* sizeof(uint32_t) );

  printf( "Allocated %u bytes of memory for %d 32-bit words at adress %p.\n\r",
               size, nWords, *mem );
  fflush( stdout );
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

// void writeAddress(void **mem, uint32_t nWords, uint8_t _64bitMachine )//pass pointer or pointer to pointer?
// {
//   printf("mem value passed: %p\n\r", mem);
//   printf("mem value passed: %p\n\r", &mem);
//   printf("mem value passed: %p\n\r", *mem);
//   //printf("mem value passed: %p\n\r", **mem);
//   //uint32_t memLowerLimit_uint = (uint32_t)mem;
//   //uint32_t memUpperLimit_uint = memLowerLimit_uint + nWords*32;
// // uint64_t memLowerLimit64_uint=0;
// // uint64_t memUpperLimit64_uint=0;
// // uint32_t memLowerLimit32_uint=0;
// // uint32_t memUpperLimit32_uint=0;
// //   //void* newMem = NULL;
// //   if(_64bitMachine == TRUE)
// //   {
// //      memLowerLimit_uint = (uint64_t)*mem;
// //      memUpperLimit_uint = memLowerLimit_uint + nWords*32;
// //   }else
// //     {
// //        memLowerLimit_uint = (uint32_t)*mem;
// //        memUpperLimit_uint = memLowerLimit_uint + nWords*32;
// //     }

//   //printf("memLowerLimit_uint: %d\n\r", memLowerLimit_uint);
//   //printf("memUpperLimit_uint: %d\n\r", memUpperLimit_uint);
//   //newMem = 
//   printf( "address to write to?\n\r");
//   fflush( stdout );
//   char addr[16];
//   uint8_t incr = 0;
//   char ch;
//   while( ((ch = getchar()) != '\n')&& incr != 16 )
//   {
    
//     if( ('0' < ch || '9' > ch)||('a' < ch || 'f' > ch)||('A' < ch || 'F' > ch) )
//     {
//       addr[incr] = ch;
//       printf("addr[%d]: %c\n\r", incr, addr[incr]);
//       incr++;
//     }
//     else(printf("invalid input: legal entries are 0-9, a-f, A-F"));
//     //i = atoi (num);
//   }
//   //while(incr !=0)addr--;

//   if(_64bitMachine == TRUE)
//   {
//     char * pEnd;
//     //char * pEnd2;
//     uint64_t userInput =   strtoull (addr, &pEnd, 16);
//     uint64_t memBegin = (uint64_t)*mem;
//     printf("userInput: %d\n\r", (uint32_t)userInput);
//     printf("memBegin: %d\n\r", (uint32_t)memBegin);
//     while(userInput!=memBegin)
//     {
//       userInput = userInput - 32;
//     }
//     if(((userInput-memBegin) >0) && (((userInput - memBegin)%32)==0) && (userInput < (membegin + 32*nWords)) )
//     {
//       uint32_t num = 0;
//       char ch;
//       while( (ch = getchar()) != '\n' )
//         {
//           if( ch == '-' )
//             {
//               printf( "ERROR: Input cannot be a negative integer.\n\r" );
//               fflush( stdout );
//               return 0;
//             }
//           else if( ch == '.' )
//             {
//               printf( "ERROR: Input must be an integer, not a double.\n\r" );
//               fflush( stdout );
//               return 0;
//             }
//           if( '9' < ch || '0' > ch )
//            {
//              continue;
//            }
//           num *= 10;
//           num += ch - '0';
//         }

//   }
//   }else
//     {
//       char * pEnd;
//       //char * pEnd2;
//       uint32_t userInput =   strtoul (addr, &pEnd, 16);
//       uint32_t memBegin = (uint32_t)(uint64_t)*mem;
//       printf("userInput: %d\n\r", userInput);
//       printf("memBegin: %d\n\r", memBegin);


//     }
// //  if(userInput == memBegin)
// //  {
// //    mem = userInput;
// //  }




//   return;
// }

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


