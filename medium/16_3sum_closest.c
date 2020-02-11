int compareInt(const void * element1, const void * element2) {
    return *(int*)element1 < *(int*)element2 ? -1 : 1;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    int closestSum = nums[0] + nums[1] + nums[2];
    int* copiedNums = (int*)malloc(sizeof(int) * numsSize);
    memcpy(copiedNums, nums, sizeof(int) * numsSize);
    qsort(copiedNums, numsSize, sizeof(*copiedNums), compareInt);
    for (int i = 0; i < numsSize - 2; i ++) {
        if (i != 0 && copiedNums[i] == copiedNums[i - 1]) {continue;}
        int j = i + 1, k = numsSize - 1;
        while (1) {
            if (j >= k) {break;}
            int currentSum = copiedNums[i] + copiedNums[j] + copiedNums[k];
            if (abs(currentSum - target) < abs(closestSum - target)) {
                closestSum = currentSum;
            }
            if (currentSum == target) {
                return target;
            } else if (currentSum < target) {
                do {
                    j ++;
                } while (j < numsSize && copiedNums[j] == copiedNums[j - 1]);
            } else {
                do {
                    k --;
                } while (k > 0 && copiedNums[k] == copiedNums[k + 1]);
            }
        }
    }
    return closestSum;
}
