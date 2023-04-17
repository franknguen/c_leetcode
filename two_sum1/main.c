#include <stdio.h> 
#include <stdlib.h> 

/** 
 * Note: The returned array must be malloced, assume caller calls free(). 
*/ 
int* twoSum(int* nums, int numsSize, int target, int* returnSize){     
    *returnSize = 2; 
    int* result = (int*) malloc(2*sizeof(int)); 
    if (result == NULL) { 
        printf("\nNot allocated."); 
    } else {
        printf("\nPass allocated.");
    }
    for (int i=0; i<numsSize; i=i+1){
        for(int j=i+1; j<numsSize; j=j+1){
            if(nums[i] + nums[j] == target){
                result[0] = i;
                result[1] = j;
            }
        }
    }
    return result; 
} 

int main() 
{ 
    int num1[] = {2, 7, 11, 15};
    int num2[] = {2, 0, 7, 15};
    int num3[] = {2, 1, 6, 8};
    int num4[] = {1, 7, 2, 15};

    int numsSize = sizeof(num1)/sizeof(num1[0]); 
    int target = 9;
    int returnSize;
    int* result1 = twoSum(num1,numsSize,target,&returnSize);
    int* result2 = twoSum(num2,numsSize,target,&returnSize);
    int* result3 = twoSum(num3,numsSize,target,&returnSize);
    int* result4 = twoSum(num4,numsSize,target,&returnSize);

    if((result1 != NULL)&&(result2 != NULL)&&(result3 != NULL)&&(result4 != NULL)){
        printf("\n [%d %d]", result1[0], result1[1]);
        printf("\n [%d %d]", result2[0], result2[1]);
        printf("\n [%d %d]", result3[0], result3[1]);
        printf("\n [%d %d]", result4[0], result4[1]);
        free(result1);
        free(result2);
        free(result3);
        free(result4);
    } else {
        printf("\nNo pair found.");
    }

    printf("\n@frk: returnSize=%d", returnSize);
    printf("\n----------------------------------"); 
    printf("\n PASS-TEST\n"); 
    return 0; 
} 
