#define STEP_LEN 32

int compareInt(const void * element1, const void * element2) {
    return *(int*)element1 < *(int*)element2 ? -1 : 1;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int* copiedNums = (int*)malloc(sizeof(int) * numsSize);
    memcpy(copiedNums, nums, sizeof(int) * numsSize);
    qsort(copiedNums, numsSize, sizeof(*copiedNums), compareInt);
    int currentResultSize = STEP_LEN;
    int** result = (int**)malloc(sizeof(int*) * STEP_LEN);
    *returnColumnSizes = (int*)malloc(sizeof(int) * STEP_LEN);
    for (int i = 0; i < numsSize; i ++) {
        if (i != 0 && copiedNums[i] == copiedNums[i - 1]) {continue;}
        int j = i + 1, k = numsSize - 1;
        while (j < k) {
            int sum = copiedNums[i] + copiedNums[j] + copiedNums[k];
            if (sum == 0) {
                result[*returnSize] = (int*)malloc(sizeof(int) * 3);
                result[*returnSize][0] = copiedNums[i];
                result[*returnSize][1] = copiedNums[j];
                result[*returnSize][2] = copiedNums[k];
                (*returnColumnSizes)[*returnSize] = 3;
                *returnSize += 1;
                if (*returnSize >= currentResultSize) {
                    result = (int**)realloc(result, sizeof(int*) * currentResultSize * 2);
                    *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * currentResultSize * 2);
                    currentResultSize *= 2;
                }
                while (j < k && copiedNums[j + 1] == copiedNums[j]) {j ++;}
                j ++;
            } else if (sum < 0) {
                do {
                    j ++;
                } while (j < numsSize && copiedNums[j] == copiedNums[j - 1]);
            } else {
                do {
                    k --;
                } while (k > 0 && copiedNums[k] == copiedNums[k + 1]);
            }
        }
    }
    free(copiedNums);
    return result;
}
