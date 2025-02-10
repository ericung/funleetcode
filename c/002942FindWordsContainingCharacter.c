int* findWordsContaining(char** words, int wordsSize, char x, int* returnSize) {
	int *indices = malloc(sizeof(int)*wordsSize);
	int count = 0;
	int j = 0;

	memset(indices, 0, sizeof(int)*wordsSize);

	// loop invariant: words[i] contains x
	for (int i = 0; i < wordsSize; i++) {
		if (strchr(words[i], x) != NULL) {
			indices[j++] = i;
			count++;
		}
	}

	*returnSize = count;

	return indices;
}
