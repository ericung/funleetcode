int maxDistance(int** arrays, int arraysSize, int* arraysColSize) {
    int result = -50000, minRes = -50000, maxRes = -50000;
    int min = arrays[0][0], max = arrays[0][arraysColSize[0] - 1];

    for (int i = 1; i < arraysSize; i++) {
        minRes = abs(min - arrays[i][arraysColSize[i] - 1]);
        maxRes = abs(arrays[i][0] - max);
        result = result < minRes ? minRes : result;
        result = result < maxRes ? maxRes : result;

        min = min > arrays[i][0] ? arrays[i][0] : min;
        max = max < arrays[i][arraysColSize[i] - 1] ? arrays[i][arraysColSize[i] - 1] : max;
    }

    return result;
}