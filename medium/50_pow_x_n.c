double myPow(double x, int n) {
    long long n_l = n;
    if (x == 0) {
        return 0;
    } else if (n_l == 0) {
        return 1;
    }
    bool negative_power = n_l < 0;
    n_l = n_l < 0 ? -n_l : n_l;
    double result = 1;
    double base = x;
    while (n_l) {
        if (n_l & 1) {
            result *= base;
        }
        base *= base;
        n_l = n_l >> 1;
    }
    return negative_power ? 1.0 / result : result;
}
