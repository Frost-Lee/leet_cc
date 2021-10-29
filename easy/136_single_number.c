int singleNumber(int* nums, int numsSize) {
    int result = 0;
    for (size_t i = 0; i < numsSize; i ++) {
        result = result ^ nums[i];
    }
    return result;
}
