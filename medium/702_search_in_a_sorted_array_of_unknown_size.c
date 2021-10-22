int search(struct ArrayReader* reader, int target) {
    size_t size_upper_bound = 1;
    while (getElement(reader, size_upper_bound) != INT_MAX) {
        size_upper_bound *= 2;
    }
    int start = 0, end = size_upper_bound - 1;
    while (start <= end) {
        int middle = start + (end - start) / 2;
        int element = getElement(reader, middle);
        if (element == target) {
            return middle;
        } else if (element < target) {
            start = middle + 1;
        } else {
            end = middle - 1;
        }
    }
    return -1;
}
