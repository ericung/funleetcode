int** matrix;

void search(int r, int c, int n);

int regionsBySlashes(char** grid, int gridSize) {
	int regions = 0;
	matrix = malloc(sizeof(int**)*(3*gridSize+1)*(3*gridSize+1));

	for (int i = 0; i < 3*gridSize + 1; i++) {
		matrix[i] = malloc(sizeof(int*)*(3*gridSize+1));
		memset(matrix[i], 0, sizeof(int*)*(3*gridSize+1));
	}

	for (int r = 0; r < gridSize; r++) {
		for (int c = 0; c < gridSize; c++) {
			if (grid[r][c] == '/') {
				matrix[3*r+3][3*c]++;
				matrix[3*r+2][3*c+1]++;
				matrix[3*r+1][3*c+2]++;
				matrix[3*r][3*c+3]++;
			} else if (grid[r][c] == '\\') {
				matrix[3*r][3*c]++;
				matrix[3*r+1][3*c+1]++;
				matrix[3*r+2][3*c+2]++;
				matrix[3*r+3][3*c+3]++;
			}
		}
	}

	for (int i = 0; i < 3*gridSize + 1; i++) {
		for (int j = 0; j < 3*gridSize + 1; j++) {
			if (matrix[i][j] == 0) {
				regions++;
				search(i, j, 3*gridSize + 1); 
			}
		}
	}

	return regions;
}

void search(int r, int c, int n) {
	matrix[r][c] = -1;

	if ((r+1 < n)&&(matrix[r+1][c] == 0)) {
		matrix[r+1][c] = -1;
		search(r+1, c, n);
	}

	if ((c+1 < n)&&(matrix[r][c+1] == 0)) {
		matrix[r][c+1] = -1;
		search(r, c+1, n);
	}

	if ((r - 1 >= 0)&&(matrix[r-1][c] == 0)) {
		matrix[r-1][c] = -1;
		search(r-1, c, n);
	}

	if ((c - 1 >= 0)&&(matrix[r][c-1] == 0)) {
		matrix[r][c-1] = -1;
		search(r, c-1, n);
	}
}
