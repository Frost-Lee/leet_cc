int minSubArrayLen(int target, int* nums, int numsSize){
    int min_length = numsSize + 1;
    int head = 0, tail = 0, sum = 0;
    for (int i = 0; i < numsSize; i ++) {
        tail += 1;
        sum += nums[i];
        while (sum >= target) {
            min_length = tail - head < min_length ? tail - head : min_length;
            sum -= nums[head];
            head += 1;
        }
    }
    return min_length == numsSize + 1 ? 0 : min_length;
}
