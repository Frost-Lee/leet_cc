char nextGreatestLetter(char* letters, int lettersSize, char target) {
    int start = 0, end = lettersSize - 1;
    while (start <= end) {
        int middle = start + (end - start) / 2;
        if (letters[middle] <= target) {
            start = middle + 1;
        } else {
            end = middle - 1;
        }
    }
    return letters[start % lettersSize];
}
