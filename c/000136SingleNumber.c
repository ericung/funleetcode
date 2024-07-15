int singleNumber(int* nums, int numsSize) {
	// Size of the hash
	int SIZE = 50000;

	// The offset since nums[k] for all k in range is
	// between -3000 and 3000
	int OFFSET = SIZE/2;

	// Allocate the hash of the size of 50000 integers
	int* hash = malloc(sizeof(int)* SIZE);

	// Initiate all values in hash to -1
	for (int i = 0; i < SIZE; i++)
	{
		hash[i] = -1;
	}

	// Loop invariant is to update hash at k where
	// k is the values between 0 and length of nums - 1
	// such that if hash[k] is -1, set it to 1 
	// otherwise update it by adding 1.
	for (int i = 0; i < numsSize; i++)
	{
		int key = nums[i] + OFFSET;

		if (hash[key] == -1)
		{
			hash[key] = 1;
		}
		else
		{
			hash[key]++;
		}
	}

	// Loop invariant is such that while hash[k] is 2 or -1
	// continue going through the loop and break once
	// hash[k] is equal to 1
	for (int i = 0; i < numsSize; i++)
	{
		int key = nums[i] + OFFSET;

		if (hash[key] == 1)
		{
			return nums[i];
		}
	}

	return -1;
}

// This particular solution has two loop invariants
