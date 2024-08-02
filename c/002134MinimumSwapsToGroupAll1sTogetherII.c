int minSwaps(int* nums, int numsSize) {
	int minimumSwaps = 9999999;

	int totalOnes = 0;

	for (int i = 0; i < numsSize; i++) {
		if (nums[i] == 1) {
			totalOnes++;
		}
	}

	int onesCount = nums[0];
	int end = 0;

	for (int i = 0; i < numsSize; i++) {
		if (i != 0) {
			onesCount -= nums[i - 1];
		}

		while (end - i + 1 < totalOnes) {
			end++;
			onesCount += nums[end % numsSize]; // modulo end % numsSize <= numsSize
		}

		if (totalOnes - onesCount < minimumSwaps) {
			minimumSwaps = totalOnes - onesCount;
		}
	}

	return minimumSwaps;
}
