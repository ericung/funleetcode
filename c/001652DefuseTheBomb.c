/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decrypt(int* code, int codeSize, int k, int* returnSize) {
	int current = 0;
	int iter = 0;
	int j = 0;
	int* retArray = malloc(sizeof(int)*codeSize);

	memset(retArray, 0, codeSize*sizeof(int));

	if (k >= 0) {
		for (int i = 0; i < codeSize; i++) {
			current = 0;
			iter = k;
			j = i+1;
			while ((j < codeSize)&&(iter > 0)) {
				retArray[i] += code[j];
				j++;
				iter--;
			}

			j = 0;

			while (iter > 0) {
				retArray[i] += code[j];
				j++;
				iter--;
				}
			}
		}
		else if ( k < 0) {
			for (int i = 0; i < codeSize; i++) {
				current = 0;
				iter = -1 * k;
				j = i - 1;

				while ((j >= 0)&&(iter > 0)) {
					retArray[i] += code[j];
					j--;
					iter--;
				}

				j = codeSize - 1;

				while (iter > 0) {

					retArray[i] += code[j];
					j--;
					iter--;
				}
			}
		}

		*returnSize = codeSize;

		return retArray;
}
