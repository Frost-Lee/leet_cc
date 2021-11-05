int findPeakElement(int* nums, int numsSize) {
    int start = 0, end = numsSize - 1;
    while (start < end) {
        int middle = start + (end - start) / 2;
        if (nums[middle] > nums[middle + 1]) {
            end = middle;
        } else {
            start = middle + 1;
        }
    }
    return start;
}
