#if 1
#include<stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize);

int main(){
    int returnSize;
    int digitsSize = 3;
    int digits[3] = {1,2,3};

    int returnSize1;
    int digitsSize1 = 3;
    int digits1[3] = {9,9,9};

    plusOne(digits, 3, &returnSize);
    printf("\n returnSize = [%d]", returnSize);
    printf("\n-----------------------------------");    
    
    plusOne(digits1, 3, &returnSize1);
    printf("\n returnSize1 = [%d]", returnSize1);
    printf("\n-----------------------------------");
    printf("\n PASS-TEST \n");
    return 0;
}
#endif 

int* plusOne(int* digits, int digitsSize, int* returnSize){
//
    if(digits == NULL || digitsSize == 0) {
        *(returnSize) = 0;
        return NULL;
    }

    int* result   =(int*)malloc(digitsSize*sizeof(int));
    int* remainder=(int*)malloc(digitsSize*sizeof(int));

    printf("\n-----------------------------------");
    *(result+digitsSize-1)    = (*(digits+digitsSize-1)+1)%10;
    *(remainder+digitsSize-1) = (*(digits+digitsSize-1)+1)/10;
    printf("\n digits[%d] = [%d]", digitsSize-1, *(digits+digitsSize-1));
    printf("\n result[%d] = [%d]", digitsSize-1, *(result+digitsSize-1));
    printf("\n remainder[%d] = [%d]", digitsSize-1, *(remainder+digitsSize-1));
    printf("\n-----------------------------------");
    for(int i=digitsSize-2; i>=0; i--)
    {
        *(result+i)    = (*(remainder+i+1) + *(digits+i))%10;
        *(remainder+i) = (*(remainder+i+1) + *(digits+i))/10;
        printf("\n digits[%d] = [%d]", i, digits[i]);
        printf("\n result[%d]    = [%d]", i,  *(result+i));
        printf("\n remainder[%d] = [%d]", i, *(remainder+i));
        printf("\n-----------------------------------");
    }
    printf("\n remainder[%d] = [%d]", 0, *remainder);
    printf("\n-----------------------------------");

    if(remainder[0] != 1){
        *returnSize = digitsSize;
        free(remainder);
        return result;
    } else {
        *returnSize = digitsSize+1;
        int* newresult=(int*)malloc((digitsSize+1)*sizeof(int));
        *(newresult)=1;
        for(int i=1; i<digitsSize+1; i++){
            *(newresult+i)=0;
        }
        free(result);
        free(remainder);
        return newresult;
    }
}
