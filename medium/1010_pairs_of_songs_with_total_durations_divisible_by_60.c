int numPairsDivisibleBy60(int* time, int timeSize) {
    long counter[60] = {};
    for (size_t i = 0; i < timeSize; i ++) {
        counter[time[i] % 60] += 1;
    }
    long result = counter[0] * (counter[0] - 1) / 2;
    for (size_t i = 1; i < 30; i ++) {
        result += counter[i] * counter[60 - i];
    }
    result += counter[30] * (counter[30] - 1) / 2;
    return (int)result;
}
