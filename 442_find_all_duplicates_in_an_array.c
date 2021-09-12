int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    size_t result_capacity = 8;
    int *result_array = (int *)malloc(sizeof(int) * result_capacity);
    *returnSize = 0;
    for (int i = 0; i < numsSize; i ++) {
        if (nums[i] - 1 == i) {
            continue;
        } else {
            int belonging_index = nums[i] - 1;
            while ((nums[i] - 1!= i) && (nums[i] != nums[belonging_index])) {
                int temp = nums[i];
                nums[i] = nums[belonging_index];
                nums[belonging_index] = temp;
                belonging_index = nums[i] - 1;
            }
        }
    }
    for (int i = 0; i < numsSize; i ++) {
        if (nums[i] - 1 != i) {
            result_array[(*returnSize) ++] = nums[i];
            if (*returnSize >= result_capacity) {
                result_capacity *= 2;
                result_array = realloc(result_array, sizeof(int) * result_capacity);
            }
        }
    }
    return result_array;
}
