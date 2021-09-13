int firstMissingPositive(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i ++) {
        if (nums[i] > 0 && nums[i] - 1 != i) {
            int belonging_index = nums[i] - 1;
            while (belonging_index >= 0 && belonging_index < numsSize && nums[belonging_index] != nums[i] && nums[i] - 1 != i) {
                int temp = nums[i];
                nums[i] = nums[belonging_index];
                nums[belonging_index] = temp;
                belonging_index = nums[i] - 1;
            }
        }
    }
    for (int i = 0; i < numsSize; i ++) {
        if (nums[i] - 1 != i) {
            return i + 1;
        }
    }
    return numsSize + 1;
}
