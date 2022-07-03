int maxSubArray(int* nums, int numsSize) {
    int previous_sum = nums[0];
    int max_sum = previous_sum;
    for (size_t i = 1; i < numsSize; i ++) {
        if (previous_sum > 0) {
            previous_sum += nums[i];
        } else {
            previous_sum = nums[i];
        }
        max_sum = previous_sum > max_sum ? previous_sum : max_sum;
    }
    return max_sum;
}
