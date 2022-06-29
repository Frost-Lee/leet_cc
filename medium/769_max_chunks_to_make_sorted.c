int maxChunksToSorted(int* arr, int arrSize) {
    long long current_sum = 0, serial_sum = 0;
    int result = 0;
    for (size_t i = 0; i < arrSize; i ++) {
        current_sum += arr[i];
        serial_sum += i;
        if (current_sum == serial_sum) {
            result += 1;
        }
    }
    return result;
}
