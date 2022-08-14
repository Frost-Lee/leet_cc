int countNumbersWithUniqueDigits(int n) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return 10;
    }
    unsigned int *dp_array = (unsigned int *)malloc(sizeof(unsigned int) * n);
    dp_array[0] = 10;
    dp_array[1] = 9 * 9;
    for (size_t i = 2; i < n; i ++) {
        dp_array[i] = (10 - i) * dp_array[i - 1];
    }
    int sum = 0;
    for (size_t i = 0; i < n; i ++) {
        sum += dp_array[i];
    }
    free(dp_array);
    return sum;
}
