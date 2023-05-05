#if 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//**************************************************************
char * convert(char * s, int numRows);
void printChar(char* s);

//**************************************************************
int main(){
    char a[] = "0123456789";
    int lena = strlen(a);

    printChar(a);
    printf("\n---------------------------------------------\n"); 
    convert(a,1);
    printf("\n---------------------------------------------\n");
    //convert(a,2);
    printf("\n---------------------------------------------\n");
    // convert(a,3);
    // printf("\n---------------------------------------------\n");
    // convert(a,4);
    // printf("\n---------------------------------------------\n");
    // convert(a,5);
    // printf("\n---------------------------------------------\n");
    // convert(a,6);
    // printf("\n---------------------------------------------\n");    
    // convert(a,7);
    // printf("\n---------------------------------------------\n");
    // convert(a,8);
    // printf("\n---------------------------------------------\n");
    // convert(a,9);
    // printf("\n---------------------------------------------\n");
    printf("\nPASS-TEST\n"); 
    return 0;
}
//**************************************************************
#endif

void printChar(char* s)
{
    int lengs = strlen(s);
    for(int i=0; i<lengs; i++)
    {
        printf("%c", s[i]);
    }
}

char * convert(char * s, int numRows){
    int lena     = strlen(s);
    if (numRows <= 1)
        return s;
    char* result = (char*)malloc((lena+1)*sizeof(char));
    result[lena] = '\0';
    int k = 0;
    printf("\n lena = %d", lena);
// i = 0
    int i = 0;
    while( i*2*(numRows-1) <= lena-1 ) 
    {

        printf("\n i=%d, {1} [%d]", i, i*2*(numRows-1));
        *(result+k++) = s[i*2*(numRows-1)];
        i++;
    }
    printf("\n---------------------------------------------\n"); 

// i = 1, numRows-2
    for (int x = 1; x <= numRows-2; x++){
        printf("\n x = %d",x);
        int m = 0;
        while( (m*2*(numRows-1) + x <= lena-1) || (m*2*(numRows-1) - x  <= lena - 1) ) 
        {
            printf("\n m = %d",m);
            printf("\n {2} [%d]", m*2*(numRows-1) - x);
            printf("\n {2} [%d]", m*2*(numRows-1) + x);
            if ( (m*2*(numRows-1) - x > 0) && ((m*2*(numRows-1) - x  <= lena - 1))) {
                *(result+k++) = s[m*2*(numRows-1) - x];
            }
            if (m*2*(numRows-1) + x <= lena-1 ) {
                *(result+k++) = s[m*2*(numRows-1) + x];
            }
            m++;
            printf("\n frk=%d", m*2*(numRows-1) + x);
        }
    }
    printf("\n---------------------------------------------\n"); 

// i = numRows-1
    int j = 0;
    while( numRows-1 + j*2*(numRows-1) <= lena-1 ) 
    {
        printf("\n j=%d, {3} [%d]", j, numRows-1 + j*2*(numRows-1));
        *(result+k++) = s[numRows-1 + j*2*(numRows-1)];
        j++;
    }

    printf("\n k = %d",k);

    printf("\n---------------------------------------------\n"); 
    printChar(result);

    return result;
}