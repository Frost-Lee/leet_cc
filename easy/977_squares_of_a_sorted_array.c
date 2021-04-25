int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* resultArray = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    int head = 0, tail = numsSize - 1;
    for (int i = numsSize - 1; i >= 0; i --) {
        if (abs(nums[head]) > abs(nums[tail])) {
            resultArray[i] = nums[head] * nums[head];
            head += 1;
        } else {
            resultArray[i] = nums[tail] * nums[tail];
            tail -= 1;
        }
    }
    return resultArray;
}
