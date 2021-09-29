int compare(const void *lhs, const void *rhs) {
    return (*(int *)lhs - *(int *)rhs);
}

int hIndex(int* citations, int citationsSize){
    qsort(citations, citationsSize, sizeof(int), compare);
    int h_index = 0;
    for (int i = citationsSize - 1; i >= 0; i --) {
        if (citations[i] >= (h_index + 1)) {
            h_index += 1;
        } else {
            break;
        }
    }
    return h_index;
}
