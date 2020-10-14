typedef enum {
    LOWER,
    UPPER
} Bound;

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *result = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    int lower_bound = binarySearch(nums, numsSize, target, LOWER);
    if (lower_bound == -1) {
        memset(result, -1, 2 * sizeof(int));
        return result;
    }
    int upper_bound = binarySearch(nums, numsSize, target, UPPER);
    result[0] = lower_bound;
    result[1] = upper_bound;
    return result;
}

int binarySearch(int* nums, int numsSize, int target, Bound bound) {
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] < target || (nums[mid] == target && bound == UPPER)) {
            left = mid + 1;
        } else if (nums[mid] > target || (nums[mid] == target && bound == LOWER)) {
            right = mid - 1;
        }
    }
    switch (bound) {
    case LOWER:
        if (left < numsSize && nums[left] == target) {return left;}
        break;
    case UPPER:
        if (right >= 0 && nums[right] == target) {return right;}
        break;
    }
    return -1;
}
