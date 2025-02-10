int mostWordsFound(char** sentences, int sentencesSize) {
	int result = 0;
	int current = 0;

	for (int i = 0; i < sentencesSize; i++) {
		char* pointer = strtok(sentences[i], " ");
		current = 0;

		while (pointer != NULL) {
			current++;

			pointer = strtok(NULL, " ");
		}

		if (current > result) {
			result = current;
		}
	}

	return result;
}
