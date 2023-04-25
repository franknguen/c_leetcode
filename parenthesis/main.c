
/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Example 1:
Input: s = "()"
Output: true
Example 2:
Input: s = "()[]{}"
Output: true
Example 3:
Input: s = "(]"
Output: false
Example 4:
Input: s = "([)]"
Output: false
Example 5:
Input: s = "{[]}"
Output: true
*/

#if 1
#include <stdio.h>
#include <string.h>
#include<stdbool.h>

bool isValid(char * s);

int main()
{
    printf("\n--------------------------");
    printf("\n %d",isValid("{{{{}}}}"));
    printf("\n--------------------------");
    printf("\nPASS TEST\n");    
    return 0;    
}
#endif

bool isValid(char * s)
{
    int length = strlen(s);

    // Stack to solve the baracket close in order
    int top = -1;
    char stack[length];

    printf("\n@frk-dbg: length=%d", length);
    for (int i=0; i<length; i++){
        if((s[i]=='{')||(s[i]=='[')||(s[i]=='('))
        {
            stack[++top]=s[i];
        } else 
        {
            if (s[i]==')')
            {
                if ((top == -1)||(stack[top]!='(')) {
                    return false;
                } else {
                    top--;
                }
            } else if (s[i]==']')
            {
                if ((top == -1)||(stack[top]!='[')) {
                    return false;
                } else {
                    top--;
                }
            } else if (s[i]=='}')
            {
                if ((top == -1)||(stack[top]!='{')) {
                    return false;
                } else {
                    top--;
                }
            }
        }
    }
    return top==-1;
}
