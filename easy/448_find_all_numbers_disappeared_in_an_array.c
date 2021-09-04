int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int i = 0;
    while (i < numsSize) {
        if (nums[nums[i] - 1] == nums[i]) {
            i += 1;
        } else {
            int temp = nums[i];
            nums[i] = nums[temp - 1];
            nums[temp - 1] = temp;
        }
    }
    int resultCapacity = 8;
    int *result = (int *)malloc(sizeof(int) * resultCapacity);
    *returnSize = 0;
    for (int i = 0; i < numsSize; i ++) {
        if (*returnSize == resultCapacity) {
            resultCapacity *= 2;
            result = realloc(result, sizeof(int) * resultCapacity);
        }
        if (i != nums[i] - 1) {
            result[(*returnSize) ++] = i + 1;
        }
    }
    return result;
}
