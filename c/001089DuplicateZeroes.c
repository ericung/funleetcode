void duplicateZeros(int* arr, int arrSize) {
    	int* temp = malloc(sizeof(int) * arrSize);
	int i = 0;
	int j = 0;

	while (j < arrSize) {
		if (arr[i] == 0)
		{
			temp[j++] = 0;
			temp[j++] = 0;
		}
		else
		{
			temp[j++] = arr[i];
		}
		i++;
	}

	for (int i = 0; i < arrSize; i++) {
		arr[i] = temp[i];
	}
}