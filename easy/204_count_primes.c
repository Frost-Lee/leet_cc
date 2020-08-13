int countPrimes(int n) {
    int primeCount = 0;
    if (n <= 2) {return 0;}
    bool* isPrimeList = (bool*)malloc(sizeof(bool) * n);
    for (int i = 0; i < n; i ++) {
        isPrimeList[i] = true;
    }
    for (int i = 2; i < n; i ++) {
        if (isPrimeList[i]) {
            primeCount += 1;
            for (int j = i + i; j < n; j += i) {
                isPrimeList[j] = false;
            }
        }
    }
    free(isPrimeList);
    return primeCount;
}
