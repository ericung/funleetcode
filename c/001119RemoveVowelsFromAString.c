// helper function to check if s[k] is a vowel
bool isVowel(char s){
	if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u')
	{
		return true;
	}

	return false;
}

char * removeVowels(char * s){
	int vowels = 0;
	int p = 0;
	int n = strlen(s) + 1;
	char *result; // keep this null so that later, we can resource optimize

	// loop invariant is while k is between 0 and n-1
	for (int i = 0; i < n; i++) {
		// check if s[k] is a variable
		if (isVowel(s[i])) {
			// increase vowels	
			vowels++;
		}
	}

	// resource optimize the result pointer
	result = malloc(sizeof(char)*(n - vowels +1));

	// loop invariant is while k is between 0 and n-1
	for (int i = 0; i < n; i++) {
		// check if s[k] is a variable
		if (!isVowel(s[i])) {
			// set result[p] to be s[i] such that
			// p is less or equal to i	
			result[p] = s[i];
			// update the p pointer
			p++;
		}
	}

	// return result
	return result;
}
