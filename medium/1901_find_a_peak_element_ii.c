int max_element_index(int **mat, int col_index, int row_count) {
    int max_index = 0;
    for (int i = 0; i < row_count; i ++) {
        if (mat[i][col_index] > mat[max_index][col_index]) {
            max_index = i;
        }
    }
    return max_index;
}

int* findPeakGrid(int** mat, int matSize, int* matColSize, int* returnSize) {
    int col_start = 0, col_end = (*matColSize) - 1;
    int *result = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    while (col_start <= col_end) {
        int col_middle = col_start + (col_end - col_start) / 2;
        int max_row_index = max_element_index(mat, col_middle, matSize);
        bool less_than_left = col_middle - 1 >= col_start && mat[max_row_index][col_middle - 1] > mat[max_row_index][col_middle];
        bool less_than_right = col_middle + 1 <= col_end && mat[max_row_index][col_middle + 1] > mat[max_row_index][col_middle];
        if (!less_than_left && !less_than_right) {
            result[0] = max_row_index;
            result[1] = col_middle;
            break;
        } else if (less_than_left) {
            col_end = col_middle - 1;
        } else {
            col_start = col_middle + 1;
        }
    }
    return result;
}
