#if 1
#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);
void merge1(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);

int main(){
    int nums1[6] = {1,2,3,0,0,0};
    int nums1Size = 6;
    int m = 3;
    int nums2[3] = {2,5,6};
    int nums2Size = 3;
    int n = 3;

    merge(nums1, nums1Size, m, nums2, nums2Size, n);
    
    printf("\n ---------------------------- \n");

    for(int i=0; i<nums1Size; i++)
    {
        printf("\n nums1[%d] = [%d]", i, nums1[i]);        
    }

    printf("\n ---------------------------- \n");
    printf("\n PASS-TEST \n");
    return 0;
}

void merge1(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int result[m+n];

    for (int i = 0, j = 0, k = 0; i < m+n; i++) {
        if (j < m && (k >= n || nums1[j] <= nums2[k])) {
            result[i] = nums1[j++];
        } else {
            result[i] = nums2[k++];
        }
    }

    for (int i = 0; i < nums1Size; i++) {
        nums1[i] = result[i];
    }
}
#endif

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int result[nums1Size];

    for(int i=0; i<m; i++)
    {
        printf("\n nums1[%d] = [%d]", i, nums1[i]);        
    }

    printf("\n ----------------------------------- \n");
    
    for(int i=0; i<n; i++)
    {
        printf("\n nums2[%d] = [%d]", i, nums2[i]);
    }

    int i = 0;
    int j = 0;
    int k = 0;

    printf("\n i==%d",i);
    printf("\n ---------------------");
    while( (j<m) && (k<n) ){
        printf("\n j==%d",j);
        printf("\n k==%d",k);
        if( nums1[j] <= nums2[k]){
            result[i] = nums1[j];
            i++;
            j++;
            printf("\n j==%d",j);
            printf("\n k==%d",k);
        } else {
            result[i] = nums2[k];
            i++;
            k++;            
            printf("\n j==%d",j);
            printf("\n k==%d",k);
        }
        printf("\n i==%d",i);
        printf("\n ---------------------");
    }

    if(j==m){
        for(int ii=i; ii<nums1Size; ii++){
            result[ii] = nums2[k++];
        }
    } else {
        for(int ii=i; ii<nums1Size; ii++){
            result[ii] = nums1[j++];
        }        
    }

    for(int i=0; i<nums1Size; i++)
    {
        nums1[i] = result[i];
    }

}
