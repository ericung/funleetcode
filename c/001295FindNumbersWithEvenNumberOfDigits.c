int findNumbers(int* nums, int numsSize) {
	// even variable result
	int even = 0;

	for (int i = 0; i < numsSize; i++)
	{
		// initiate the variables
		// n is loop invariant variable for nums[i]
		// count is digit counter for nums[i]
		int n = nums[i];
		int count = 0;

		// loop invariant is the condition that n > 0
		while (n > 0)
		{
			// updates the loop invariant by updating
			// n / 10	
			n = n / 10;
			count++;
		}

		// count modulo 2 is equal to 0
		if (count % 2 == 0)
		{
		    even++;
		}
	}

	// return the result even
	return even;
}
