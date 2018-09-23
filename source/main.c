#include "project1.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 20


/* 
* references: 
* https://stackoverflow.com/questions/46376046/dynamically-allocating-memory-to-save-user-input-in-it
* https://en.wikipedia.org/wiki/C_dynamic_memory_allocation
*
*
*/

int main( int argc, const char* argv[])
{

char *input_ptr = (char*)calloc(MAX_INPUT_LENGTH,1 * sizeof(char));


printf("hello, enter 'help' for help menu\n\r");
fflush( stdout );

while(1)
{
    printf(">");
    fflush( stdout );
    fgets(input_ptr,MAX_INPUT_LENGTH,stdin);
    if(input_ptr[0] == 'h' && input_ptr[1] == 'e' && input_ptr[2] == 'l' && input_ptr[3] == 'p' )
    {
        printHelpMenu();
    }
    else if(input_ptr[0] == 'q' && input_ptr[1] == 'u' && input_ptr[2] == 'i' && input_ptr[3] == 't' )
    {
        free(input_ptr);
        break;
    }
    else printf("invalid input\n\r");
}

    return 0;
}

void printHelpMenu()
{
    printf("enter 'help' to see help menu\n\renter 'quit' to end program\n\r");
}