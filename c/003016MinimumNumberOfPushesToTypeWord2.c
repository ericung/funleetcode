#define SIZE 26

int compareChar(const void* a, const void* b);
int compare(const void* a, const void* b);

int minimumPushes(char* word) {
	int* count = malloc(sizeof(int)*SIZE);
	int result = 0;

	memset(count, 0, sizeof(int)*SIZE);

	qsort(word, strlen(word), sizeof(char), compareChar);

	// chunking after sorting
	for (int i = 0; i < 26; i++) {
		int f = strchr(word, (char*)('a' + i));
		if (f != NULL) {
			int r = strrchr(word, (char*)('a' + i));
			count[i] = r - f + 1;
		}
	}

	qsort(count, SIZE, sizeof(int), compare);

	for (int i = 0; i < SIZE; i++) {
		result += count[i] * (1 + i / 8);
	}

	free(count);

	return result;
}

int compareChar(const void* a, const void* b) {
	return (*(char*)a - *(char*)b);
}

int compare(const void* a, const void* b) {
	return (*(int*)b - *(int*)a);
}
