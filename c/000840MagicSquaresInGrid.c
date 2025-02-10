int numMagicSquaresInside(int** grid, int gridSize, int* gridColSize) {
	int result = 0;
	int row1 = 0;
	int row2 = 0;
	int row3 = 0;
	int col1 = 0;
	int col2 = 0;
	int col3 = 0;
	int diagonal1 = 0;
	int diagonal2 = 0;
	int *hashmap = malloc(sizeof(int)*17);

	for (int i = 0; i < gridSize-2; i++) {
		for (int j = 0; j < *gridColSize-2; j++) {
			memset(hashmap,0, sizeof(int)*17);
			row1 = grid[i][j] + grid[i+1][j] + grid[i+2][j];
			row2 = grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
			row3 = grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2];
			diagonal1 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
			diagonal2 = grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j];
			col1 = grid[i][j] + grid[i][j+1] + grid[i][j+2];
			col2 = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
			col3 = grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];

			for (int r = i; r <= i+2; r++) {
				for (int c = j; c <= j+2; c++) {
					if ((grid[r][c] == 0)||(grid[r][c] > 9)||(hashmap[grid[r][c]] == 1)) {
						hashmap[16] = 1;
					}

					hashmap[grid[r][c]] = 1;
				}
			}

			if ((hashmap[16] == 0)&&(row1 == row2)&&(row1 == row3)&&(diagonal1 == diagonal2)&&(col1 == col2)&&(col1 == col3)) {
				result++;
			}
		}
	}

	return result;
}
