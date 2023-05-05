/***********************************************************************/
/**
 * main - main program, test case
 * problems: convert a string into zigzag string
 */
/***********************************************************************/
#if 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// void printChar(char* s);
int climbStairs(int n);

int main(){
    int n1 = 1;
    int n2 = 2;
    int n3 = 3;
    int n4 = 4;
    int n5 = 5;
    int n6 = 6;
    printf("---------------------------------------------------\n");
    printf("\n result = [%d]", climbStairs(n1));
    printf("\n result = [%d]", climbStairs(n2));
    printf("\n result = [%d]", climbStairs(n3));
    printf("\n result = [%d]", climbStairs(n4));
    printf("\n result = [%d]", climbStairs(n5));
    printf("\n result = [%d]", climbStairs(n6));    
    printf("\n---------------------------------------------------");
    printf("\nPASS-TEST\n");
    return 0;
}
#endif
/***********************************************************************/
/**
 * climbStairs - 
 * @n:            input number
 *    
 * You are climbing a staircase. It takes n steps to reach the top.
 * Each time you can either climb 1 or 2 steps. 
 * In how many distinct ways can you climb to the top?
 *
 * return:        int 
 */

int climbStairs(int n){
    int arr_helper[45];

    arr_helper[0] = 1;
    arr_helper[1] = 2;

    for(int i=0; i<43; i++){
        arr_helper[i+2] = arr_helper[i] + arr_helper[i+1];
    }

    return arr_helper[n-1];
}

// int climbStairs(int n){
//     if (n==1) {
//         return 1;
//     } else if (n==2){
//         return 2;
//     } else if(n > 2 ){
//         return climbStairs(n-1) + climbStairs(n-2);
//     }
//     return 0;
// }
/***********************************************************************/