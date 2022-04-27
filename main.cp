#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void parse_parm(char *input_str, char *output_str, int index){  //given void function
    
    int i = 0;     //counter for when while loops nth times (index) then wont meet parameters 
    
    //loops while output_str has not reached the end of the char string as well as not reached the nth argument (index)
    while (output_str != NULL && i != index) { 
        char a = *output_str;               //stores where the current *output_str points to char a
        printf("%c\n", a);                  //prints char a, clarifying data is a char, then moving to new line
        output_str = strtok (NULL, ",");    //strtok, parsed respected to the deliminator
        i++;                                //increments index counter by 1
    }
}

int main ()
{
    char input_str[] ="1,2,3,c,+,+";        //declared string separated by commas
    char *output_str;
    output_str = strtok (input_str,",");    //strtok, parsed respected to the deliminator

    parse_parm(input_str,output_str,3);     //forwards variables to void function

    return 0;                               //terminates program
}
