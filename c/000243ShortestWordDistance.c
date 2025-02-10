int shortestDistance(char** wordsDict, int wordsDictSize, char* word1, char* word2) {
	int word1Index = -1;
	int word2Index = -1;
	int i = 0;
	int min = 9999999999;

	// i between 0 and wordsDictSize
	while (i < wordsDictSize) {
		if (strcmp(wordsDict[i], word1) == 0) {
			word1Index = i;
		}

		if (strcmp(wordsDict[i], word2) == 0) {
			word2Index = i;
		}

		if ((word1Index != -1)&&(word2Index != -1)) {
			min = min > abs(word1Index - word2Index) ? abs(word1Index - word2Index) : min;
		}

		i++;
	}

	return min;
}
