#include "stdio.h"
#include "stdlib.h"

int removeElement(int* nums, int numsSize, int val) {
	// place variable
	int place = 0;

	// loop invariant is while the iterator is between 0 and numsSize
	// and if nums[i] != val, update the placement
	for (int i = 0; i < numsSize; i++)
	{
		// conditional nums[i] != val
		if (nums[i] != val)
		{
			// update the current nums[place] = nums[i]
			nums[place] = nums[i];
			// update place
			place++;
		}
	}

	// place
	return place;
}

/*
 * Loop Invariant: Updates the place variable value if nums[k] != val 
 * while k is in between 0 and numsSize - 1
 * While the invariant is true, update nums[place] = nums[k]
 */

int main() {
	int nums[4] = {3,2,2,3};
	int result = removeElement(nums, 4, 3);
	printf("%d\n", result);

	return 0;
}

