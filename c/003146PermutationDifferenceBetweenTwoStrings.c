int findPermutationDifference(char* s, char* t) {
	int *a = malloc(sizeof(int)*26);
	int *b = malloc(sizeof(int)*26);
	int diff = 0;

	// both loop invariants while k is between 0 and strlen(s)
	for (int i = 0; i < strlen(s); i++) {
		a[s[i] - 'a'] = i;
		b[t[i] - 'a'] = i;
	}

	for (int i = 0; i < strlen(s); i++) {
		diff += abs(a[s[i] - 'a'] - b[s[i] - 'a']);
	}

	return diff;
}
