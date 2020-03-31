int minPatches(int* nums, int numsSize, int n) {
    long int maxRepresentation = 1;
    int patchCount = 0;
    int arrayIndex = 0;
    while (maxRepresentation <= n) {
        if (arrayIndex < numsSize && nums[arrayIndex] <= maxRepresentation) {
            maxRepresentation += nums[arrayIndex ++];
        } else {
            patchCount += 1;
            maxRepresentation *= 2;
        }
    }
    return patchCount;
}
