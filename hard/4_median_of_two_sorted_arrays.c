int compared_value(int *nums, int numsSize, int index) {
    if (index < 0) {
        return INT_MIN;
    } else if (index >= numsSize) {
        return INT_MAX;
    } else {
        return nums[index];
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size < nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    int start = -1, end = nums1Size - 1;
    int left_part_size = (nums1Size + nums2Size + 1) / 2;
    while (start <= end) {
        int middle = start + (end - start) / 2;
        int nums2_partition = left_part_size - middle - 2;
        int nums1_left = compared_value(nums1, nums1Size, middle);
        int nums1_right = compared_value(nums1, nums1Size, middle + 1);
        int nums2_left = compared_value(nums2, nums2Size, nums2_partition);
        int nums2_right = compared_value(nums2, nums2Size, nums2_partition + 1);
        if (nums1_left > nums2_right) {
            end = middle - 1;
        } else if (nums2_left > nums1_right) {
            start = middle + 1;
        } else {
            double result = 0.0;
            if ((nums1Size + nums2Size) & 1) {
                result = nums1_left > nums2_left ? nums1_left : nums2_left;
            } else {
                int left = nums1_left > nums2_left ? nums1_left : nums2_left;
                int right = nums1_right < nums2_right ? nums1_right : nums2_right;
                result = (left + right) / 2.0;
            }
            return result;
        }
    }
    return 0.0;
}
