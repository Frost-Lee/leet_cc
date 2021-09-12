int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    for (int i = 0; i < numsSize; i ++) {
        if (nums[i] - 1 != i) {
            int belonging_index = nums[i] - 1;
            while ((nums[i] - 1 != i) && (nums[belonging_index] != nums[i])) {
                int temp = nums[i];
                nums[i] = nums[belonging_index];
                nums[belonging_index] = temp;
                belonging_index = nums[i] - 1;
            }
        }
    }
    int *result = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    for (int i = 0; i < numsSize; i ++) {
        if (nums[i] - 1 != i) {
            result[0] = nums[i];
            result[1] = i + 1;
            break;
        }
    }
    return result;
}
