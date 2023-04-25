#if 0
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
#endif

#if 1
#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main() 
{
    int nums1[4] = {2, 7, 11, 15};
    int nums2[4] = {3, 8, 2, 1};
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
#endif

int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    *returnSize = 2;
    int* result = malloc((*returnSize)*sizeof(int));
    for (int i = 0; i < numsSize; i++) 
    {
        for (int j = i + 1; j < numsSize; j++) 
        {
            if (*(nums+i) + *(nums+j) == target) 
            {
                *(result)   = i;
                *(result+1) = j;
                return result;
            }
        }
    }
    return result;
}
