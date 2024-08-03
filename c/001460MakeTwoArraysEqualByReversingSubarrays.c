bool canBeEqual(int* target, int targetSize, int* arr, int arrSize) {
	int a[1001] = {0};
	int b[1001] = {0};

	for (int i = 0; i < targetSize; i++) {
		a[target[i]]++;
		b[arr[i]]++;
	}

	// loop invariant is while k is between 0 and targetSize
	// and the condition that a[arr[k]] >= 0 and b[targetSize[k]] >= 0
	for (int i = 0; i < targetSize; i++) {
		a[arr[i]]--;
		b[target[i]]--;

		if ((a[arr[i]] < 0)||(b[target[i]] < 0)) {
			return false;
		}
	}

	return true;
}
