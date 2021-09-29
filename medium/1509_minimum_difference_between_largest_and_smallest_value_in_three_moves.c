int compare(const void *lhs, const void *rhs) {
    return (*(int *)lhs - *(int *)rhs);
}

int minDifference(int* nums, int numsSize){
    if (numsSize <= 4) {
        return 0;
    }
    qsort(nums, numsSize, sizeof(int), compare);
    int min_difference = nums[numsSize - 1] - nums[0];
    for (size_t i = 0; i < 4; i ++) {
        int local_difference = nums[i + numsSize - 4] - nums[i];
        min_difference = local_difference < min_difference ? local_difference : min_difference;
    }
    return min_difference;
}
