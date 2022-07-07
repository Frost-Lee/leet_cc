int removeElement(int* nums, int numsSize, int val) {
    int last_index = numsSize - 1;
    while (last_index >= 0 && nums[last_index] == val) {
        last_index -= 1;
    }
    for (int i = 0; i <= last_index; i ++) {
        if (nums[i] == val) {
            int temp = nums[i];
            nums[i] = nums[last_index];
            nums[last_index] = temp;
            while (last_index >= 0 && nums[last_index] == val) {
                last_index -= 1;
            }
        }
    }

    return last_index + 1;
}
