int calculateTime(char* keyboard, char* word) {
	int *hashmap = malloc(sizeof(int*)*26);
	int result = 0;

	for (int i = 0;  i < strlen(keyboard); i++) {
		hashmap[keyboard[i]-'a'] = i;
	}

	result += hashmap[word[0] - 'a'];

	for (int i = 1; i < strlen(word); i++) {
		result += abs(hashmap[word[i-1]-'a']-hashmap[word[i]-'a']);
	}

	return result;
}
