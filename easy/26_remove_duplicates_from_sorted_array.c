int removeDuplicates(int* nums, int numsSize) {
    int slow = 0, fast = 0;
    for (int i = 0; i < numsSize; i ++) {
        if (slow == 0 || nums[fast] != nums[slow - 1]) {
            nums[slow] = nums[fast];
            slow += 1;
        }
        fast += 1;
    }
    return slow;
}
