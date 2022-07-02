int rob(int* nums, int numsSize) {
    int current = 0, previous = 0, next_previous = 0;
    for (size_t i = 0; i < numsSize; i ++) {
        int temp_next_previous = next_previous, temp_previous = previous;
        next_previous = previous;
        previous = current;
        int include_i_value = nums[i] + next_previous;
        int exclude_i_value = previous;
        current = include_i_value > exclude_i_value ? include_i_value : exclude_i_value;
    }
    return current;
}
