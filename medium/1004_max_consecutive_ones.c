int longestOnes(int* A, int ASize, int K) {
    int max_length = 0, head = 0;
    int window_0_count = 0;
    for (int i = 0; i < ASize; i ++) {
        if (A[i] == 0) {
            window_0_count += 1;
        }
        while (window_0_count > K) {
            if (A[head] == 0) {
                window_0_count -= 1;
            }
            head += 1;
        }
        max_length = fmax(max_length, i - head + 1);
    }
    return max_length;
}
