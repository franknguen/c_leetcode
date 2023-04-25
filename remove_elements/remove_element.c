#if 1
#include <stdio.h>

int removeElement(int* nums, int numsSize, int val);

int main(){
    int array[7]={1,2,3,4,5,5,5};
    int numsSize = 7;
    int val = 5;
    removeElement(array,numsSize,val);
    return 0;
}
#endif 

int removeElement(int* nums, int numsSize, int val){
    int result = 0;

    if (numsSize == 0){
        nums = NULL;
        result = 0;
        return result;
    }

    // /*Test array only*/
    for(int i=0; i<numsSize; i++){
        printf("\n@frk-dbg: Array[%d]=[%d]",i,nums[i]);
    }

    /*Stack to save output values*/
    int top = -1;
    int stack[numsSize];
    printf("\n--------------------------------------");    

    for (int j = 0; j < numsSize; j++ ){
        if (nums[j] != val){
            printf("\n@frk-dbg: nums[%d]=[%d]",j,nums[j]);
            stack[++top] = nums[j];
            printf("\n@frk-dbg: stack[%d]=[%d]",top,stack[top]);
        }
    }
    result = top + 1;
    //nums = stack;
    printf("\n--------------------------------------");    

    for(int i=0; i<numsSize; i++){
        nums[i] = (i <= top) ? stack[i] : 0;
        // printf("\n@frk-dbg: num[%d]=[%d]",i,nums[i]);
    }
    printf("\n--------------------------------------");    

    /*Result stores here*/
    printf("\n@frk-dbg: result=[%d]", result);
    return result;
}
