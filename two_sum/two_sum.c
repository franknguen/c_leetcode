#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main() 
{
    int nums1[] = {2, 7, 11, 15};
    int nums2[] = {3, 8, 2, 1};
    int target = 9;
    int returnSize;

    int* result = twoSum(nums2, sizeof(nums2)/sizeof(nums2[0]), target, &returnSize);

    if (result != NULL) {
        printf("[%d, %d]\n", result[0], result[1]);
        free(result);
    } else {
        printf("No pair found\n");
    }
    return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    int* result = malloc(2 * sizeof(int));
    *returnSize = 2;
    for (int i = 0; i < numsSize; i++) 
    {
        for (int j = i + 1; j < numsSize; j++) 
        {
            if (nums[i] + nums[j] == target) 
            {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return result;
}
