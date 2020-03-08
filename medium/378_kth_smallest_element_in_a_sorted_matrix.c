int countNoGreaterThan(int** matrix, int matrixSize, int target);
    
int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k) {
    int head = matrix[0][0], tail = matrix[matrixSize - 1][matrixSize - 1];
    while (head < tail) {
        int middle = (head + tail) / 2;
        int noGreaterThanMiddleCount = countNoGreaterThan(matrix, matrixSize, middle);
        if (noGreaterThanMiddleCount < k) {
            head = middle + 1;
        } else {
            tail = middle;
        }
    }
    return tail;
}

int countNoGreaterThan(int** matrix, int matrixSize, int target) {
    int row = matrixSize - 1, col = 0;
    int count = 0;
    while (row >= 0 && col < matrixSize) {
        if (matrix[row][col] <= target) {
            count += row + 1;
            col ++;
        } else {
            row --;
        }
    }
    return count;
}
