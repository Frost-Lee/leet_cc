int findComplement(int num) {
    int temp = num, bit_count = 0;
    while (temp) {
        temp = temp >> 1;
        bit_count += 1;
    }
    long mask;
    while (bit_count > 0) {
        mask = (mask << 1) | 1;
        bit_count -= 1;
    }
    return mask & (~num);
}
