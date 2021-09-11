int findDuplicate(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i ++) {
        if (nums[i] != i + 1) {
            int reorder_index = i;
            while (nums[reorder_index] != reorder_index + 1) {
                int belonging_index = nums[reorder_index] - 1;
                if (nums[belonging_index] == nums[reorder_index]) {
                    return nums[reorder_index];
                } else {
                    int temp = nums[reorder_index];
                    nums[reorder_index] = nums[belonging_index];
                    nums[belonging_index] = temp;
                }
            }
        }
    }
    return -1;
}
