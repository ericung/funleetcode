long long maxPoints(int** points, int pointsSize, int* pointsColSize) {
    long long dp[pointsSize][*pointsColSize];
    long long max = 0;
    long long value = 0;

    for(int j = 0; j < *pointsColSize; j++) {
        dp[0][j] = (long long)points[0][j];

        if (dp[0][j] > max) {
            max = dp[0][j];
        }
    }

    for (int i = 1; i < pointsSize; i++) {
        value = 0;
        for (int j = 0; j < *pointsColSize; j++) {
            value = (value - 1) < dp[i-1][j] ? dp[i-1][j] : (value - 1);
            dp[i][j] = value;
        }

        value = 0;
        for (int j = *pointsColSize-1; j >= 0; j--) {
            value = value - 1 < dp[i-1][j] ? dp[i-1][j] : value - 1;
            dp[i][j] = value < dp[i][j] ? dp[i][j] : value;
            dp[i][j] += points[i][j];

            if (dp[i][j] > max) {
                max = dp[i][j];
            }
        }
    }

    return max;
}