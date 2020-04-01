void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortColors(int* nums, int numsSize) {
    int head = 0, tail = numsSize - 1;
    for (int i = head; i <= tail; i ++) {
        while (i >= head && i <= tail && (nums[i] == 0 || nums[i] == 2)) {
            if (nums[i] == 0) {
                swap(&nums[i], &nums[head ++]);
            } else if (nums[i] == 2) {
                swap(&nums[i], &nums[tail --]);
            }
        }
    }
}
