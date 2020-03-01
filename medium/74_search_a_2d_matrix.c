bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    if (matrixSize == 0 || *matrixColSize == 0) {return false;}
    int head = 0, tail = matrixSize * *matrixColSize - 1;
    while (head <= tail) {
        int mid = (head + tail) / 2;
        int midValue = matrix[mid / *matrixColSize][mid % *matrixColSize];
        if (midValue == target) {
            return true;
        } else if (midValue > target) {
            tail = mid - 1;
        } else if (midValue < target) {
            head = mid + 1;
        }
    }
    return false;
}
