/***********************************************************************/
/**
 * main - main program, test case
 * problems: convert a string into zigzag string
 */
/***********************************************************************/
#if 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printChar(char* s);

int main(){
    char a[] = "0123456789";
    printf("---------------------------------------------------\n");
    printChar(a);    
    printf("\n---------------------------------------------------");
    printf("\nPASS-TEST\n");
    return 0;
}
#endif
/***********************************************************************/
/**
 * printChar - print a string
 * @s:       input string
 * return:   void 
 */
void printChar(char* s)
{
    int lengs = strlen(s);
    for(int i=0; i<lengs; i++)
    {
        printf("%c", s[i]);
    }
}
/***********************************************************************/