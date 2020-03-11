int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0 || *matrixColSize == 0) {*returnSize = 0;return NULL;}
    int* container = (int*)malloc(sizeof(int) * matrixSize * *matrixColSize);
    int startColIndex = 0, startRowIndex = 0;
    int endColIndex = *matrixColSize, endRowIndex = matrixSize;
    int containerIndex = 0;
    while (startColIndex < endColIndex && startRowIndex < endRowIndex) {
        for (int i = startColIndex; i < endColIndex; i ++) {
            container[containerIndex ++] = matrix[startRowIndex][i];
        }
        for (int i = startRowIndex + 1; i < endRowIndex; i ++) {
            container[containerIndex ++] = matrix[i][endColIndex - 1];
        }
        if (endRowIndex - startRowIndex > 1 && endColIndex - startColIndex > 1) {
            for (int i = endColIndex - 2; i >= startColIndex; i --) {
                container[containerIndex ++] = matrix[endRowIndex - 1][i];
            }
            for (int i = endRowIndex - 2; i > startRowIndex; i --) {
                container[containerIndex ++] = matrix[i][startColIndex];
            }
        }
        startRowIndex ++;
        startColIndex ++;
        endRowIndex --;
        endColIndex --;
    }
    *returnSize = matrixSize * *matrixColSize;
    return container;
}
