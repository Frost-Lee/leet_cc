int compare(const void *lhs, const void *rhs) {
    return (*(int *)rhs - *(int *)lhs);
}

int minOperations(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int nums_1_sum = 0, nums_2_sum = 0;
    for (size_t i = 0; i < nums1Size; i ++) {
        nums_1_sum += nums1[i];
    }
    for (size_t i = 0; i < nums2Size; i ++) {
        nums_2_sum += nums2[i];
    }
    int *large_array, *small_array;
    int large_array_size, small_array_size;
    int difference = 0;
    if (nums_1_sum == nums_2_sum) {
        return 0;
    } else if (nums_1_sum > nums_2_sum) {
        large_array = nums1;
        large_array_size = nums1Size;
        small_array = nums2;
        small_array_size = nums2Size;
        difference = nums_1_sum - nums_2_sum;
    } else if (nums_1_sum < nums_2_sum) {
        large_array = nums2;
        large_array_size = nums2Size;
        small_array = nums1;
        small_array_size = nums1Size;
        difference = nums_2_sum - nums_1_sum;
    }
    int *large_gains = (int *)malloc(sizeof(int) * large_array_size);
    int *small_gains = (int *)malloc(sizeof(int) * small_array_size);
    for (size_t i = 0; i < large_array_size; i ++) {
        large_gains[i] = large_array[i] - 1;
    }
    for (size_t i = 0; i < small_array_size; i ++) {
        small_gains[i] = 6 - small_array[i];
    }
    int large_pointer = 0, small_pointer = 0;
    qsort(large_gains, large_array_size, sizeof(int), compare);
    qsort(small_gains, small_array_size, sizeof(int), compare);
    while (difference > 0) {
        if (large_pointer >= large_array_size && small_array >= small_array_size) {
            large_pointer = -1;
            small_pointer = 0;
            break;
        }
        if (large_pointer >= large_array_size) {
            difference -= small_gains[small_pointer];
            small_pointer += 1;
        } else if (small_pointer >= small_array_size) {
            difference -= large_gains[large_pointer];
            large_pointer += 1;
        } else {
            if (large_gains[large_pointer] > small_gains[small_pointer]) {
                difference -= large_gains[large_pointer];
                large_pointer += 1;
            } else {
                difference -= small_gains[small_pointer];
                small_pointer += 1;
            }
        }
    }
    free(large_gains);
    free(small_gains);
    return large_pointer + small_pointer;
}
