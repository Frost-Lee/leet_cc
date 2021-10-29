int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int *result = (int *)malloc(sizeof(int) * 2);
    memset(result, 0, sizeof(int) * 2);
    *returnSize = 2;
    int n1_x_n2 = 0;
    for (size_t i = 0; i < numsSize; i ++) {
        n1_x_n2 ^= nums[i];
    }
    long classification_mask = 1;
    while (!(n1_x_n2 & classification_mask)) {
        classification_mask = classification_mask << 1;
    }
    for (size_t i = 0; i < numsSize; i ++) {
        if (classification_mask & nums[i]) {
            result[0] ^= nums[i];
        } else {
            result[1] ^= nums[i];
        }
    }
    return result;
}
