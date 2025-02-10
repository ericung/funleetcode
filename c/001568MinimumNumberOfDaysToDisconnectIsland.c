// need to refactor and reanalyze.

struct Node {
    int row;
    int col;
    int length;
};

int direction[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int diagonals[4][2] = {{-1,-1}, {1,1}, {1,-1}, {-1, 1}};
int MINIMUM = 100000;
int* count;

int search(int** grid, int n, int m, int r, int c);
int minSwap();
bool checkDiagonals(int** grid, int n, int m, int r, int c);
bool checkSides(int** grid, int n, int m, int r, int c);

int minDays(int** grid, int gridSize, int* gridColSize) {
    int result = MINIMUM;
    int cur = 10000;
    count = malloc(sizeof(int*)*1000);
    
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j] != 0) {
                cur = search(grid, gridSize, *gridColSize, i, j);

                if (cur < result) {
                    result = cur;
                }
            }
        }
    }

    return result == MINIMUM ? 0 : result;
}

int search(int** grid, int n, int m, int r, int c) {
    
    int q = 1; // queue top
    int qc = 0; // queue pointer

    struct Node* queue = malloc(sizeof(struct Node*)*5000);
    int hashmap[n][m];
    int currentR;
    int currentC;
    int length;
    int maxlength = 0;
    bool sides = false;

    for (int i = 0; i < n; i++) {
        memset(hashmap, 0, sizeof(hashmap));
    }

    memset(count, 0, sizeof(int*)*1000);

    queue[0].row = r;
    queue[0].col = c;
    queue[0].length = 1;
    count[1] = queue[0].length;
    hashmap[r][c] = 1;

    while (qc != q) {
        if (checkDiagonals(grid, n, m, queue[qc].row, queue[qc].col)) {
            return 1;
        }
        
        if (checkSides(grid, n, m, queue[qc].row, queue[qc].col)) {
            sides = true;
        }

        for (int i = 0; i < 4; i++) {
            currentR = queue[qc].row + direction[i][0];
            currentC = queue[qc].col + direction[i][1]; 
            length = queue[qc].length + 1;

            if ((0 <= currentR)&&(currentR < n)&&(0 <= currentC)&&(currentC < m)&&(grid[currentR][currentC] == 1)&&(hashmap[currentR][currentC] == 0)) {
                queue[q].row = currentR;
                queue[q].col = currentC;
                queue[q++].length = length;
                count[length]++;
                hashmap[currentR][currentC] = length;
                if (length > maxlength) {
                    maxlength = length;
                }
            }
        }
        qc++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((grid[i][j] == 1)&&(hashmap[i][j] == 0)) {
                return 0;
            }
        }
    }

    if ((maxlength > 2)&&(sides == true)) {
        return 1;
    }
    return minSwap();
}

int minSwap() {
    int consecutiveOnes = 0;
    int min = MINIMUM;

    for (int i = 1; i < 1000; i++) {
        if (count[i] == 1) {
            consecutiveOnes++;

            if (consecutiveOnes == 1) {
                if (((i -1 < 0)||((i - 1 >= 0)&&(count[i-1] == 0)))&&((count[i+1] == 0))) {
                    return 1;
                }
                if (((i -1 < 0)||((i - 1 >= 0)&&(count[i-1] > 0)))&&((count[i+1] > 0))) {
                    return 1;
                }
            }

            if (consecutiveOnes == 2) {
                if (((i -2 < 0)||((i - 2 >= 0)&&(count[i-2] == 0)))
                &&((i + 1 > 1000)||((i+1<1000)&&(count[i+1] == 0)))) {
                    return 2;
                }

                return 1;
            }
        } else {
            consecutiveOnes = 0;
        }

        if ((count[i] > 1)&&(count[i] < min)) {
            min = count[i];
        }
    }

    return min == MINIMUM ? 0 : min;
}

bool checkDiagonals(int** grid, int n, int m, int r, int c) {
    if ((n > 2)&&(m > 2)) {
        int up = r - 1;
        int down = r + 1;
        int left = c - 1;
        int right = c + 1;

        for (int i = 0; i < 4; i+=2) {
            int cornerAR = r + diagonals[i][0];
            int cornerAC = c + diagonals[i][1];
            int cornerBR = r + diagonals[i+1][0];
            int cornerBC = c + diagonals[i+1][1];

            if ((0 <= cornerAR)&&(cornerAR < n)&&(0 <= cornerAC)&&(cornerAC < m)&&(grid[cornerAR][cornerAC] == 0)&&(cornerBR >= 0)&&(cornerBR < n)&&(cornerBC == 0)&&(cornerBC < m)&&(grid[cornerBR][cornerBC] == 0)) {
                return true;
            }
        }
    }

    return false;
}

bool checkSides(int** grid, int n, int m, int r, int c) {
    if (( n > 2)&&(m > 2)) {
        bool verticalFlip = true;
        bool horizontalFlip = true;

        int i = 0;
        while (i < n) {
            if (i == r) {
                i++;
            }
            else {
                if (grid[i][c] == 1) {
                    verticalFlip = false;
                    break;
                }

                i++;
            }
        }

        i = 0;
        while (i < m) {
            if (i == c) {
                i++;
            }
            else {
                if (grid[r][i] == 1) {
                    horizontalFlip = false;
                    break;
                }

                i++;
            }
        }

        return verticalFlip | horizontalFlip;
    }

    return false;
}
