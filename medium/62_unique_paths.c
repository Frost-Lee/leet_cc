int uniquePaths(int m, int n) {
    int* dpArray = (int*)malloc(sizeof(int) * m * n);
    for (int i = 0; i < m * n; i ++) {
        dpArray[i] = 1;
    }
    for (int i = 1; i < m; i ++) {
        for (int j = 1; j < n; j ++) {
            dpArray[i * n + j] = dpArray[(i - 1) * n + j] + dpArray[(i * n + j - 1)];
        }
    }
    int result = dpArray[m * n - 1];
    free(dpArray);
    return result;
}
