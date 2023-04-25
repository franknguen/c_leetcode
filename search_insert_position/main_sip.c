#if 1
#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target);

int main(){
    int nums1[4] = {1,3,5,6}, target1 = 5;
    int nums2[4] = {1,3,5,6}, target2 = 2;
    int nums3[4] = {1,3,5,6}, target3 = 7;

    searchInsert(nums1, 4, target1);
    searchInsert(nums2, 4, target2);
    searchInsert(nums3, 4, target3);

    printf("\n---------------------------------------------"); 
    printf("\nPASS-TEST\n"); 
    return 0; 
}
#endif

int searchInsert(int* nums, int numsSize, int target){
    int result=0;

    printf("\n target = %d", target);
    printf("\n numsSize = %d", numsSize);
    for(int i=0; i<numsSize; i++){
        printf("\n nums[%d] = %d", i, nums[i]);
    }
    if(nums[0] >= target)
    {
        printf("\n Result = [%d]", 0);
        printf("\n---------------------------------------");
        return 0;
    } else if (target == nums[numsSize-1]){
                printf("\n Result = [%d]", numsSize-1);
                printf("\n---------------------------------------");
                return numsSize-1;
            } else if (target > nums[numsSize-1]){
                printf("\n Result = [%d]", numsSize);
                printf("\n---------------------------------------");
                return numsSize;
            } else {
                for (int i=1; i<numsSize; i++)
                {
                    if ((nums[i] >= target))
                    {
                        result = i;
                        break;
                    }
                }                
            }
    printf("\n Result = [%d]", result);
    printf("\n---------------------------------------");
    return result;
}