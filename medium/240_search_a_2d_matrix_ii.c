bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int row = matrixRowSize - 1, col = 0;
    if (matrixRowSize == 0 || matrixColSize == 0) {return false;}
    while (row >= 0 && col < matrixColSize) {
        int value = matrix[row][col];
        if (value == target) {
            return true;
        } else if (value > target) {
            row --;
        } else if (value < target) {
            col ++;
        }
    }
    return false;
}
