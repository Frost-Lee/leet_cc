int digit_square_sum(int n) {
    int sum = 0;
    while (n != 0) {
        sum += pow(n % 10, 2);
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow = n, fast = n;
    do {
        slow = digit_square_sum(slow);
        fast = digit_square_sum(digit_square_sum(fast));
    } while (slow != fast);
    return slow == 1;
}
