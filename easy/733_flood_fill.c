void identify_fill(int **image, size_t row_count, size_t col_count, size_t sr, size_t sc, int source_color) {
    if (image[sr][sc] == source_color) {
        image[sr][sc] = -image[sr][sc] - 1;
        if (sr > 0) {
            identify_fill(image, row_count, col_count, sr - 1, sc, source_color);
        }
        if (sc > 0) {
            identify_fill(image, row_count, col_count, sr, sc - 1, source_color);
        }
        if (sr < row_count - 1) {
            identify_fill(image, row_count, col_count, sr + 1, sc, source_color);
        }
        if (sc < col_count - 1) {
            identify_fill(image, row_count, col_count, sr, sc + 1, source_color);
        }
    }
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes) {
    *returnSize = imageSize;
    int *return_col_sizes = (int *)malloc(sizeof(int) * imageSize);
    for (size_t i = 0; i < imageSize; i ++) {
        return_col_sizes[i] = *imageColSize;
    }
    *returnColumnSizes = return_col_sizes;
    int source_color = image[sr][sc];
    identify_fill(image, imageSize, *imageColSize, sr, sc, source_color);
    for (size_t i = 0; i < imageSize; i ++) {
        for (size_t j = 0; j < *imageColSize; j ++) {
            if (image[i][j] == -source_color - 1) {
                image[i][j] = newColor;
            }
        }
    }
    return image;
}
