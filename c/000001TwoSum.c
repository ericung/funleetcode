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

	*returnSize = 0;
	return NULL;
} 