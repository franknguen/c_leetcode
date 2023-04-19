#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    int stack[numsSize];
    int top = -1;
    printf("\n@frk-dbg: nums[xxx]=%d",nums[0]);
    stack[++top] = nums[0];

    for (int i=0; i<numsSize; i++)
    {
        printf("\n@frk-dbg: nums[%d]=%d",i,nums[i]);
    }
    int k;
    for (int i=1; i<numsSize; i++)
    {
        printf("\n@frk-dbg: i=%d",i);
        k = 0;
        for (int j=0; j <= top; j++)
        {
            printf("\n@frk-dbg: j=%d",j);    
            if (nums[i] == stack[j])
            {
                printf("\n hehe");
                k++;
                break;
            }
        }
        printf("\n@frk-dbg: k=%d",k);
        if (k == 0)
        {
            printf("\n@frk-dbg: nums[xxx]=%d",nums[i]);
            stack[++top] = nums[i];
        }
    }
    printf("\n@frk-dbg: top=%d",top);
    for (int i=0; i<numsSize; i++)
    {
        printf("\n@frk-dbg: stack[%d]=%d",i,stack[i]);
        nums[i]=stack[i];
    }    
    return top+1;
}

int main(){
    int arr1[10] = {1,1,2,2,3,4,4,4,4,4};    
    int arr2[10] = {1,2,3,4,5,5,5,5,5,5};
    int arr3[10] = {1,1,1,1,1,1,1,1,1,1};
    removeDuplicates(arr1,10);
    printf("\n--------------------------");
    //removeDuplicates(arr2,10);
    printf("\n--------------------------");
    //removeDuplicates(arr3,10);
    printf("\n--------------------------");
    printf("\nPASS TEST\n");   
}
