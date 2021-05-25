#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

int findUnsortedSubarray(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;
    while (left < numsSize - 1 && nums[left] <= nums[left + 1]) {
        left += 1;
    }
    while (right > 0 && nums[right - 1] <= nums[right]) {
        right -= 1;
    }
    if (left >= right) {
        return 0;
    }
    int rangeMin = INT_MAX, rangeMax = INT_MIN;
    for (int i = left; i <= right; i ++) {
        rangeMin = MIN(rangeMin, nums[i]);
        rangeMax = MAX(rangeMax, nums[i]);
    }
    while (left > 0 && nums[left - 1] > rangeMin) {
        left -= 1;
    }
    while (right < numsSize - 1 && nums[right + 1] < rangeMax) {
        right += 1;
    }
    return right - left + 1;
}
