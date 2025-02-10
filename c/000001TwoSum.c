#include "stdio.h"
#include "stdlib.h"

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int* q = nums;
	for (int i = 0; i < numsSize; i++)
	{
		int* r = q+1;

		for (int j = i+1; j < numsSize; j++)
		{
			if (*q == target - *r)
			{
				int* result = malloc(sizeof(int) * 2);
				result[0] = i;
				result[1] = j;
				*returnSize = 2;
				return result;
			}
			r++;
		}

		q++;
	}

	int* result = malloc(sizeof(int));
	*returnSize = 0;
	return result;
} 

int main() {
	int nums1[4] = {2, 7, 11, 15};
	int* returnSize = malloc(sizeof(int));
	int* result = twoSum(nums1, 4, 9, returnSize);
	if (*returnSize > 0) {
		printf("%d %d\n", nums1[result[0]], nums1[result[1]]);
	}

	int nums2[3] = {3, 2, 4};
	int* returnSize2 = malloc(sizeof(int));
	int* result2 = twoSum(nums2, 3, 6, returnSize2);
	if (*returnSize2 > 0) {
		printf("%d %d\n", nums2[result2[0]], nums2[result2[1]]);
	}

	int nums3[2] = {3, 3};
	int* returnSize3 = malloc(sizeof(int));
	int* result3 = twoSum(nums3, 2, 6, returnSize3);
	if (*returnSize3 > 0) {
		printf("%d %d\n", nums3[result3[0]], nums3[result3[1]]);
	}

	return 0;
}
