int SIZE = 1e7 + 41; // 1e7 + 41 is the minimum for this hash function to work

int convertToInt(char* s);

char* kthDistinct(char** arr, int arrSize, int k) {
	int *hashmap = malloc(sizeof(int*)*SIZE);
	int *arrHash = malloc(sizeof(int*)*arrSize);
	int ik = 0;

	memset(hashmap, 0, sizeof(int*)*SIZE);
	memset(arrHash, 0, sizeof(int*)*arrSize);

	for (int i = 0; i < arrSize; i++) {
		int key = convertToInt(arr[i]);
		hashmap[key] += 1;
	}

	// for k in 0 to arrSize
	// key converts string arr[k] to a hashcode
	// while the condition that ik (the variable of
	// the ith unique element in arr) < k holds
	for (int i = 0 ; i < arrSize; i++) {
		int key = arrHash[i]; // reduce call to convertToInt

		if (hashmap[key] == 1) {
			ik++;

			if (ik == k) {
				return arr[i];
			}
		}
	}

	// free memory so it doesn't break
	free(hashmap);

	return "";
}

int convertToInt(char* s) {
	int key = 0;
	int n = strlen(s);

	for (int k = 0; k < n; k++) {
		key = 41*key + s[k];
	}

	return key % SIZE;
}
