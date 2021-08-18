int nextIndex(int index, int *nums, int numsSize, bool *isForward) {
    if (index < 0 || index >= numsSize || (*isForward ^ (nums[index] >= 0))) {
        return -1;
    }
    int nextIndex = (((index + nums[index]) % numsSize) + numsSize) % numsSize;
    *isForward = nums[index] >= 0;
    if (nextIndex == index) {
        return -1;
    }
    return nextIndex;
}

bool hasCircle(int startIndex, int* nums, int numsSize, bool *circleMask) {
    int slow = startIndex, fast = slow;
    bool isSlowForward = (bool)(nums[slow] >= 0), isFastForward = (bool)(nums[fast] >= 0);
    do {
        circleMask[slow] = true;
        slow = nextIndex(slow, nums, numsSize, &isSlowForward);
        fast = nextIndex(fast, nums, numsSize, &isFastForward);
        fast = nextIndex(fast, nums, numsSize, &isFastForward);
    } while (fast != slow && fast >= 0 && slow >= 0);
    return slow >= 0 && fast >= 0;
}

bool circularArrayLoop(int* nums, int numsSize) {
    bool *circleMask = (bool *)malloc(sizeof(bool) * numsSize);
    bool hasCycle = false;
    memset(circleMask, 0, numsSize);
    for (int i = 0; i < numsSize; i ++) {
        if (!circleMask[i] && hasCircle(i, nums, numsSize, circleMask)) {
            hasCycle = true;
            break;
        }
    }
    free(circleMask);
    return hasCycle;
}
