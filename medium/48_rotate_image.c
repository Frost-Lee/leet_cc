void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int rowEnd = matrixSize / 2;
    int colEnd = (matrixSize + 1) / 2;
    for (int row = 0; row < matrixSize / 2; row ++) {
        for (int col = 0; col < (matrixSize + 1) / 2; col ++) {
            int temp = matrix[row][col];
            int oppositeCol = matrixSize - col - 1;
            int oppositeRow = matrixSize - row - 1;
            matrix[row][col] = matrix[oppositeCol][row];
            matrix[oppositeCol][row] = matrix[oppositeRow][oppositeCol];
            matrix[oppositeRow][oppositeCol] = matrix[col][oppositeRow];
            matrix[col][oppositeRow] = temp;
        }
    }
}
