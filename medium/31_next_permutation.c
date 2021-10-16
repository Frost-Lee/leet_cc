void nextPermutation(int* nums, int numsSize) {
    int active_index = -1;
    int previous_value = INT_MAX;
    for (size_t i = 0; i < numsSize; i ++) {
        if (nums[i] > previous_value) {
            active_index = i - 1;
        }
        previous_value = nums[i];
    }
    int swap_start_index = 0;
    int next_min_index = -1;
    int next_min = INT_MAX;
    if (active_index >= 0) {
        for (size_t i = active_index + 1; i < numsSize; i ++) {
            if (nums[i] > nums[active_index] && nums[i] <= next_min) {
                next_min_index = i;
                next_min = nums[i];
            }
        }
        int temp = nums[next_min_index];
        nums[next_min_index] = nums[active_index];
        nums[active_index] = temp;
        swap_start_index = active_index + 1;
    }
    int swap_end_index = numsSize - 1;
    while (swap_start_index < swap_end_index) {
        int temp = nums[swap_start_index];
        nums[swap_start_index] = nums[swap_end_index];
        nums[swap_end_index] = temp;
        swap_start_index += 1;
        swap_end_index -= 1;
    }
}
