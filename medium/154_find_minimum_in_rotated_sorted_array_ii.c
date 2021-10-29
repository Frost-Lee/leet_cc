int find_rotation_start(int *nums, int nums_size) {
    int start = 0, end = nums_size - 2;
    while (start <= end) {
        if (nums[end] > nums[end + 1]) {
            return end + 1;
        }
        while (start < end && nums[start] == nums[start + 1]) {
            start += 1;
        }
        while (start < end && nums[end] == nums[end - 1]) {
            end -= 1;
        }
        int middle = start + (end - start) / 2;
        if (nums[middle] > nums[middle + 1]) {
            return middle + 1;
        } else {
            if (nums[middle] < nums[start]) {
                end = middle - 1;
            } else if (nums[middle] >= nums[start]) {
                start = middle + 1;
            }
        }
    }
    return 0;
}

int findMin(int* nums, int numsSize) {
    if (numsSize == 1) {
        return nums[0];
    }
    int rotation_start = find_rotation_start(nums, numsSize);
    return nums[rotation_start];
}
