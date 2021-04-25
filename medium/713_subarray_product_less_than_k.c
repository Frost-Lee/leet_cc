int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
    long long int product;
    int count = 0;
    int tail = -1;
    for (int i = 0; i < numsSize; i ++) {
        tail = tail < i - 1 ? i - 1 : tail;
        if (i == 0 || tail == i - 1) {
            product = 1;
        } else {
            product /= nums[i - 1];
        }
        while (tail < numsSize - 1 && product * nums[tail + 1] < k) {
            product = product * nums[tail + 1];
            tail += 1;
        }
        count += tail - i + 1;
    }
    return count;
}
