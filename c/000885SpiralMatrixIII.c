const int direction[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};

int** spiralMatrixIII(int rows, int cols, int rStart, int cStart, int* returnSize, int** returnColumnSizes) {
	int **result = malloc(sizeof(int*)*rows*cols);
	int scale = 1;
	int cs = 0;
	int d = 2;
	int count = 1;
	int r = rStart;
	int c = cStart;

	*result = malloc(sizeof(int*)*2);
	result[0][0] = rStart;
	result[0][1] = cStart;
	*returnSize = count;
	*returnColumnSizes = malloc(sizeof(int*) * (cols * rows));
	**returnColumnSizes = 2;

	// for every two times the loop goes through, increase scale(magnitude, etc)
	// so that the scale*direction fits a perfect spiral forming a matrix
	while (count < rows * cols) {
		r = r + direction[d][0];
		c = c + direction[d][1];

		// 
		if ((0 <= r)&&(r < rows)&&(0 <= c)&&(c < cols)) {
			result[count] = malloc(sizeof(int*)*2);
			result[count][0] = r;
			result[count][1] = c;
			(*returnColumnSizes)[count++] = 2;
			*returnSize = count;
		}

		cs++;

		// automaton
		if (cs >= scale) {
			cs = 0;
			d++;

			if (d % 2 == 0) {
				scale++;
			}

			if (d >= 4) {
				d = 0;
			}
		}
	}

	return result;
}
