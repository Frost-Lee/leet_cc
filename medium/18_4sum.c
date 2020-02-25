int compareInt(const void * element1, const void * element2) {
    return *(int*)element1 < *(int*)element2 ? -1 : 1;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int* copiedNums = (int*)malloc(sizeof(int) * numsSize);
    memcpy(copiedNums, nums, sizeof(int) * numsSize);
    qsort(copiedNums, numsSize, sizeof(*copiedNums), compareInt);
    int containerSize = 16;
    int** resultContainer = (int**)malloc(sizeof(int*) * containerSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * containerSize);
    for (int i = 0; i < numsSize; i ++) {
        if (i != 0 && copiedNums[i] == copiedNums[i - 1]) {continue;}
        for (int j = i + 1; j < numsSize; j ++) {
            if (j != i + 1 && copiedNums[j] == copiedNums[j - 1]) {continue;}
            int p = j + 1, q = numsSize - 1;
            while (p < q) {
                int sum = copiedNums[i] + copiedNums[j] + copiedNums[p] + copiedNums[q];
                if (sum == target) {
                    resultContainer[*returnSize] = (int*)malloc(sizeof(int) * 4);
                    resultContainer[*returnSize][0] = copiedNums[i];
                    resultContainer[*returnSize][1] = copiedNums[j];
                    resultContainer[*returnSize][2] = copiedNums[p];
                    resultContainer[*returnSize][3] = copiedNums[q];
                    (*returnColumnSizes)[*returnSize] = 4;
                    if (++ (*returnSize) >= containerSize) {
                        containerSize *= 2;
                        resultContainer = (int**)realloc(resultContainer, sizeof(int*) * containerSize);
                        *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * containerSize);
                    }
                    do {
                        p ++;
                    } while (p < numsSize && copiedNums[p] == copiedNums[p - 1]);
                } else if (sum < target) {
                    do {
                        p ++;
                    } while (p < numsSize && copiedNums[p - 1] == copiedNums[p]);
                } else if (sum > target) {
                    do {
                        q --;
                    } while (q >= 0 && copiedNums[q + 1] == copiedNums[q]);
                }
            }
        }
    }
    free(copiedNums);
    return resultContainer;
}
