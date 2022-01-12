int** multiply(int** mat1, int mat1Size, int* mat1ColSize, int** mat2, int mat2Size, int* mat2ColSize, int* returnSize, int** returnColumnSizes) {
    int **result = (int **)malloc(sizeof(int *) * mat1Size);
    *returnSize = mat1Size;
    *returnColumnSizes = (int *)malloc(sizeof(int) * mat1Size);
    for (size_t i = 0; i < mat1Size; i ++) {
        result[i] = (int *)malloc(sizeof(int) * (*mat2ColSize));
        memset(result[i], 0, sizeof(int) * (*mat2ColSize));
        (*returnColumnSizes)[i] = (*mat2ColSize);
    }
    for (size_t i = 0; i < mat1Size; i ++) {
        for (size_t j = 0; j < (*mat1ColSize); j ++) {
            if (mat1[i][j] != 0) {
                for (size_t k = 0; k < (*mat2ColSize); k ++) {
                    if (mat2[j][k] != 0) {
                        result[i][k] += mat1[i][j] * mat2[j][k];
                    }
                }
            }
        }
    }
    return result;
}
