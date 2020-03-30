void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* nums, int numsSize) {
    int pivot = nums[numsSize - 1];
    int i = -1;
    for (int j = 0; j < numsSize - 1; j ++) {
        if (nums[j] <= pivot) {
            i ++;
            swap(&nums[i], &nums[j]);
        }
    }
    swap(&nums[i + 1], &nums[numsSize - 1]);
    return i + 1;
}

int findKthLargest(int* nums, int numsSize, int k) {
    int index = partition(nums, numsSize);
    if (index == numsSize - k) {
        return nums[index];
    } else if (index < numsSize - k) {
        return findKthLargest(nums + index + 1, numsSize - index - 1, k);
    } else if (index > numsSize - k) {
        return findKthLargest(nums, index, k - (numsSize - index));
    }
    return 0;
}
