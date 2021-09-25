int findLonelyPixel(char** picture, int pictureSize, int* pictureColSize) {
    int *row_single_cols = (int *)malloc(sizeof(int) * pictureSize);
    int *col_single_rows = (int *)malloc(sizeof(int) * (*pictureColSize));
    for (size_t i = 0; i < pictureSize; i ++) {
        row_single_cols[i] = -1;
    }
    for (size_t i = 0; i < (*pictureColSize); i ++) {
        col_single_rows[i] = -1;
    }
    for (size_t i = 0; i < pictureSize; i ++) {
        for (size_t j = 0; j < (*pictureColSize); j ++) {
            if (picture[i][j] == 'B') {
                if (row_single_cols[i] == -1) {
                    row_single_cols[i] = j;
                } else {
                    row_single_cols[i] = -2;
                }
                if (col_single_rows[j] == -1) {
                    col_single_rows[j] = i;
                } else {
                    col_single_rows[j] = -2;
                }
            }
        }
    }
    int lonely_count = 0;
    for (size_t i = 0; i < pictureSize; i ++) {
        if (i < (*pictureColSize) && row_single_cols[i] >= 0 && col_single_rows[row_single_cols[i]] == i) {
            lonely_count += 1;
        }
    }
    free(row_single_cols);
    free(col_single_rows);
    return lonely_count;
}
