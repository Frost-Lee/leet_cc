char * convertToTitle(int n) {
    short digits[16] = {};
    int digitCount = 0;
    while (n > 0) {
        n -= 1;
        digits[digitCount ++] = (short)(n % 26);
        n /= 26;
    }
    char * result = (char*)malloc(sizeof(char) * (digitCount + 1));
    for (int i = 0; i < digitCount; i ++) {
        result[i] = (char)('A' + digits[digitCount - 1 - i]);
    }
    result[digitCount] = '\0';
    return result;
}
