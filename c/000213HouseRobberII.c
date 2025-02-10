int rob(int* nums, int numsSize) {
	if (numsSize == 1) {
		return nums[0];
	}

	int prev = 0, prevprev = 0;

	for (int i = 0; i <= numsSize - 2; ++i) {
		int temp = prev;
		prev = max(nums[i] + prevprev, prev);
		prevprev = temp;
	}

	int current1 = prev;

	prev = 0, prevprev = 0;

	for (int i = 1; i <= numsSize - 1; ++i) {
		int temp = prev;
		prev = max(nums[i] + prevprev, prev);
		prevprev = temp;
	}

	int current2 = prev;

	return current1 > current2 ? current1 : current2;
}

int max(int value1, int value2) {
	return value1 > value2 ? value1 : value2;
}
