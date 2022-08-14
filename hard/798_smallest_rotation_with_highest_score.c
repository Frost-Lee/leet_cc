int bestRotation(int* nums, int numsSize) {
    int *score_list = (int *)malloc(sizeof(int) * numsSize);
    memset(score_list, 0, sizeof(int) * numsSize);
    for (size_t i = 0; i < numsSize; i ++) {
        score_list[(i - nums[i] + numsSize + 1) % numsSize] -= 1;
    }
    for (size_t i = 1; i < numsSize; i ++) {
        score_list[i] = score_list[i - 1] + 1 + score_list[i];
    }
    int max_score = -numsSize - 1, max_index = 0;
    for (size_t i = 0; i < numsSize; i ++) {
        if (score_list[i] > max_score) {
            max_score = score_list[i];
            max_index = i;
        }
    }
    free(score_list);
    return max_index;
}
