int numJewelsInStones(char* jewels, char* stones) {
	int lowerStones[26] = {0}; // lower digit stones
	int upperStones[26] = {0}; // upper digit stones
	int result = 0;

	for (int i = 0; i < strlen(jewels); i++) {
		int upper = jewels[i] - 'A';
		int lower = jewels[i] - 'a';

		if ((upper >= 0)&&(upper < 26)) {
			upperStones[upper]++;
		}

		if ((lower >= 0)&&(lower < 26)) {
			lowerStones[lower]++;
		}
	}

	// loop invariant is while k is between 0 and strlen(stones)
	// and condition is if stones[k] - 'a' is between 0 and 25 and it is contained
	// in lowerStones update result by 1
	// otherwise stones[k] - 'A' is between 0 and 25 and it is contained 
	// in upperStones update result by 1
	for (int i = 0; i < strlen(stones); i++) {
		int lower = stones[i] - 'a';
		int upper = stones[i] - 'A';

		if ((lower >= 0)&&(lower < 26)&&(lowerStones[lower] == 1)) {
			result++;
		} 
		else if ((upper >= 0)&&(upper < 26)&&(upperStones[upper] == 1)) {
			result++;
		}
	}

	return result;
}
