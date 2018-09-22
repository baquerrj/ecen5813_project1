#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
uint8_t main( uint8_t argc, char* argv[])
{
   uint8_t nargs = argc - 1;
   if( 0 < nargs )
   {
      uint8_t arg = argc - nargs;
      printf( "arg = %u argc = %u\n", argc-nargs, argc );
      // argv[ 0 ] is the name of program. So skip of over it.
      if( ( arg == nargs ) && 
            ( ( 0 == strcmp( "-h", argv[ arg ] ) ) ||
              ( 0 == strcmp( "--help", argv[ arg ] ) )) )
      {
         printf( "Help\n" );
         printf( "   -n    " );
         printf( "Specifies number of 32-bit words of memory to allocate.\n         " );
         printf( "Number must be a non-negative integer.\n" );
         return 1;
      }

      while( arg < argc )
      {
         //printf( "arg at top of while loop = %u\n", arg );

         if( ( 0 == strcmp( "-n", argv[ arg ] ) ) && 2 <= nargs )
         {
            uint8_t num = atoi( argv[ arg + 1 ] );
            if( 0 <= num )
            {
               printf( "%u 32-bit words of memory to allocate.\n", num );
            }
         }
         else if( 1 == ( arg % 2 ) )
         {
            if( 0 == strcmp( "-n", argv[ arg ] ))
            {
               printf( "ERROR: Option %s without input!\n", argv[ arg ] );
               return 1;
            }
            else
            {
               printf( "ERROR: Unknown option %s!\n", argv[ arg ] );
               return 1;
            }
         }
         arg++;
      }
   }
   else if( 0 == nargs )
   {
      printf( "ERROR: No arguments were passed!\n" );
   }

   return 1;
}


