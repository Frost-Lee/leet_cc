int rob(int* nums, int numsSize) {
    int *dp = (int *)malloc(sizeof(int) * numsSize);
    for (size_t i = 0; i < numsSize; i ++) {
        int skip_previous = i >= 2 ? dp[i - 2] : 0;
        int previous = i >= 1 ? dp[i - 1] : 0;
        dp[i] = skip_previous + nums[i] > previous ? skip_previous + nums[i] : previous;
    }
    int result = dp[numsSize - 1];
    free(dp);
    return result;
}
