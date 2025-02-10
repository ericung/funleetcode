int compare(const void* a, const void* b);

int rangeSum(int* nums, int numsSize, int n, int left, int right) {
	int total = numsSize *(numsSize + 1)/2;
	int* subarraySum = malloc(sizeof(int*)*total);
	int p = 0;
	int sum = 0;

	// loop invariant for every i between 0 and n - 1 and every p between 0 and n(n+1)/2 - 1,
	// p such that p is in the set {0, (i-1) + n+1, (i-1) + 2(n), ...}
	// subarray[p] = nums[i]
	// for every j between i + 1 and n-1,
	// p such that p is between i to i + n-1-i
	// subarray[p] = subarray[p-1] + nums[j]
	// by analyzing the p in this manner,
	// a solution that runs in nlgn can be made out
	for (int i = 0; i < numsSize; i++) {
		subarraySum[p++] = nums[i];
		for (int j = i + 1; j < numsSize; j++) {
			subarraySum[p++] = subarraySum[p-1] + nums[j];
		}
	}

	qsort(subarraySum, total, sizeof(int), compare);

	for (int i = left - 1; i < right; i++) {
		sum = (sum + subarraySum[i])%((int)(pow(10,9) + 7));
	}

	return sum;
}

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}
