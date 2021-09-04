int missingNumber(int* nums, int numsSize) {
    int i = 0;
    while (i < numsSize) {
        if (nums[i] == i) {
            i += 1;
        } else {
            if (nums[i] < numsSize) {
                int temp = nums[i];
                nums[i] = nums[nums[i]];
                nums[temp] = temp;
            } else {
                i ++;
            }
        }
    }
    for (int i = 0; i < numsSize; i ++) {
        if (nums[i] != i) {
            return i;
        }
    }
    return numsSize;
}
