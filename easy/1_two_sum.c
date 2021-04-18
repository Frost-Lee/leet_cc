int* globalNums = NULL;

int compare( const void* a, const void* b) {
     int int_a = globalNums[*(unsigned short*)a], int_b = globalNums[*(unsigned short*)b];
     return int_a < int_b ? -1 : int_a > int_b ? 1 : 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    globalNums = nums;
    int* result = (int*)malloc(sizeof(int) * 2);
    unsigned short* indexList = (unsigned short*)malloc(sizeof(unsigned short) * numsSize);
    for (int i = 0; i < numsSize; i ++) {
        indexList[i] = i;
    }
    qsort(indexList, numsSize, sizeof(unsigned short), compare);
    int start = 0, end = numsSize - 1;
    while (start < end) {
        int sum = nums[indexList[start]] + nums[indexList[end]];
        if (sum < target) {
            start += 1;
        } else if (sum > target) {
            end -= 1;
        } else {
            result[0] = indexList[start];
            result[1] = indexList[end];
            break;
        }
    }
    free(indexList);
    *returnSize = 2;
    return result;
}
