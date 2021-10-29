int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = imageSize;
    int **new_image = (int **)malloc(sizeof(int *) * imageSize);
    int *col_sizes = (int *)malloc(sizeof(int) * imageSize);
    for (size_t i = 0; i < imageSize; i ++) {
        new_image[i] = (int *)malloc(sizeof(int) * (*imageColSize));
        col_sizes[i] = *imageColSize;
    }
    *returnColumnSizes = col_sizes;
    for (size_t i = 0; i < imageSize; i ++) {
        for (size_t j = 0; j < (*imageColSize); j ++) {
            new_image[i][j] = !(image[i][(*imageColSize) - 1 - j]);
        }
    }
    return new_image;
}
