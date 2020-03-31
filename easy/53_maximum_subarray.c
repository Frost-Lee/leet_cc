int maxSubArray(int* nums, int numsSize) {
    int max = INT_MIN;
    int sum = 0;
    for (int i = 0; i < numsSize; i ++) {
        sum = sum < 0 ? nums[i] : sum + nums[i];
        max = max > sum ? max : sum;
    }
    return max;
}
