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

char * convert(char * s, int numRows);
void printChar(char* s);

int main(){
    char a[] = "0123456789";
    int lena = strlen(a);
    printf("\n---------------------------------------------------");
    printf("\nString input = [%s]", a);
    printf("\nTest %d -----",1); 
    convert(a,1);
    printf("\nTest %d -----",2);
    convert(a,2);
    printf("\nTest %d -----",3);
    convert(a,3);
    printf("\nTest %d -----",4);
    convert(a,4);
    printf("\nTest %d -----",5);
    convert(a,5);
    printf("\nTest %d -----",6);
    convert(a,6);
    printf("\nTest %d -----",7);    
    convert(a,7);
    printf("\nTest %d -----",8);
    convert(a,8);
    printf("\nTest %d -----",9);
    convert(a,9);
    printf("\nTest %d -----",10);
    convert(a,10);
    printf("\n---------------------------------------------------");
    printf("\nPASS-TEST\n");
    return 0;
}
#endif
/***********************************************************************/
/**
 * convert - convert a string s into a zigzag string
 * @s:       input string
 * @numRows: #rows of zigzag string
 * return:   zigzag string 
 */
char * convert(char * s, int numRows){
    int lena     = strlen(s);

	/*
	 * handle the trivial test-case
	 */
    if ( (numRows <= 1) || (numRows >= lena)){
        printf("\n zigzag = [%s]", s);
        return s;
    }

    /*
    *  result holds the output of convert function
    */
    char* result = (char*)malloc((lena+1)*sizeof(char));
    result[lena] = '\0';

    /*
    *  k holds the index of output
    */
    int k = 0;

    /*
     * to add the index with %(2(numRows-1))==0 
     * into the row = 0 of result
     */
    int i = 0;
    while( (i*2*(numRows-1)) <= lena-1 ) 
    {
        *(result+k++) = s[i*2*(numRows-1)];
        i++;
    }

    /*
     * to add the index with %(2(numRows-1))== -x or +x where
     * x is from 1 to (numRows-2) 
     * into the row = 0 of result
     */
    for (int x = 1; x <= numRows-2; x++){
        int m = 0;
        while( ((m*2*(numRows-1)+x) <= (lena-1)) || ((m*2*(numRows-1)-x) <= (lena-1)) ) 
        {
            if ( ((m*2*(numRows-1)-x) > 0) && ((m*2*(numRows-1)-x) <= (lena-1))) {
                *(result+k++) = s[m*2*(numRows-1)-x];
            }
            if ( (m*2*(numRows-1)+x) <= (lena-1) ) {
                *(result+k++) = s[m*2*(numRows-1)+x];
            }
            m++;
        }
    }

    /*
     * to add the index with %(2(numRows-1))==0 
     * into the row = 0 of result
     */
    int j = 0;
    while( (numRows-1 + j*2*(numRows-1)) <= (lena-1) ) 
    {
        *(result+k++) = s[numRows-1 + j*2*(numRows-1)];
        j++;
    }
	
    printf("\n zigzag = [%s]", result);
    return result;
}
/***********************************************************************/