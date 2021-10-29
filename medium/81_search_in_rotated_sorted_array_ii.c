int find_rotation_start(int *nums, int nums_size) {
    int start = 0, end = nums_size - 2;
    if (nums[end] > nums[end + 1]) {
        return end + 1;
    }
    while (start <= end) {
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
    return -1;
}

int binary_search(int *nums, int start, int end, int target) {
    while (start <= end) {
        int middle = start + (end - start) / 2;
        if (nums[middle] == target) {
            return middle;
        } else if (nums[middle] < target) {
            start = middle + 1;
        } else if (nums[middle] > target) {
            end = middle - 1;
        }
    }
    return -1;
}

bool search(int* nums, int numsSize, int target) {
    if (numsSize == 1) {
        return nums[0] == target;
    }
    int rotation_start = find_rotation_start(nums, numsSize);
    if (rotation_start < 0) {
        return binary_search(nums, 0, numsSize - 1, target) >= 0;
    } else {
        int left_result = binary_search(nums, 0, rotation_start - 1, target);
        if (left_result < 0) {
            return binary_search(nums, rotation_start, numsSize - 1, target) >= 0;
        } else {
            return true;
        }
    }
}
