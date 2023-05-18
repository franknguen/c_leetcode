/***********************************************************************/
/**
    LeetCode 
    Purpose: #94, binary tree inorder traversal
    @author: Frank Nguen
    @date:   0x-05-2023
    https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
*/
/***********************************************************************/
#if 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/***********************************************************************/
// funs declerations
/***********************************************************************/

void printChar(char* s);

/***********************************************************************/
/**
 * main - main program, test case
 * problems: convert a string into zigzag string
 */
/***********************************************************************/

int main()
{
    printf("\n start testing ....................................");
    printf("\n---------------------------------------------------");
    
    char a[] = "0123456789";
    
    printf("---------------------------------------------------\n");
    printChar(a);    

    printf("\n---------------------------------------------------");
    printf("\nPASS-TEST\n");
    return 0;
}

#endif

/***********************************************************************/
// funs implements
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
