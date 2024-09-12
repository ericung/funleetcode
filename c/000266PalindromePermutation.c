bool canPermutePalindrome(char* s) {
	int* characters = malloc(sizeof(int*)*27);
	int odds = 0;

	memset(characters, 0, sizeof(int*)*27);

	for (int i = 0; i < strlen(s); i++) {
		characters[s[i] - 'a']++;
	}

	for (int i = 0; i < 27; i++) {
		if (characters[i] % 2 == 1) {
			odds++;
		}
	}

	return odds > 1 ? false : true;
}
