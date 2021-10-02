int consecutiveNumbersSum(int n) {
    int sum_term = 0;
    int count = 0;
    int max_sum_length = sqrt(2 * n);
    for (int i = 0; i < max_sum_length; i ++) {
        sum_term += i;
        if ((n - sum_term) % (i + 1) == 0) {
            count += 1;
        }
    }
    return count;
}
