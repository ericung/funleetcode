// comp
int comp(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int majorityElement(int* nums, int numsSize) {
	int max = 1;
	int maxVar = nums[0];
	int current = 1;
	int var = nums[0];

	// qsort is an implementation of quicksort
	qsort (nums, numsSize, sizeof(int), comp);

	// loop invariant is where k is between 0 and numsSize -1
	for (int i = 0; i < numsSize; i++) {
		// if nums[i] is the current variable
		if (nums[i] == var) {
		    current++;
		}
		else {
			// reset
			current = 1;
			var = nums[i];
		}

		// current is greater than max
		if (current >= max)
		{
			// set max and current variable
			max = current;
			maxVar = var;
		}
	}

	return maxVar;
}
