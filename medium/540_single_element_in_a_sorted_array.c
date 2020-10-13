int singleNonDuplicate(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int mid = (left + right) / 2, mid_left = -1;
        if (mid + 1 <= right && nums[mid + 1] == nums[mid]) {
            mid_left = mid;
        } else if (mid - 1 >= 0 && nums[mid - 1] == nums[mid]) {
            mid_left = mid - 1;
        } else {
            return nums[mid];
        }
        if ((mid_left - left) % 2 == 0) {
            left = mid_left + 2;
        } else {
            right = mid_left - 1;
        }
    }
    return -1;
}
