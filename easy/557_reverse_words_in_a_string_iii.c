void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}


char * reverseWords(char * s) {
    int head = 0, tail = 0;
    while (tail <= strlen(s)) {
        if (s[tail] == ' ' || s[tail] == '\0') {
            if (head < tail) {
                int i = head, j = tail - 1;
                while (i < j) {
                    swap(s + (i ++), s + (j --));
                }
            }
            tail += 1;
            head = tail;
        } else {
            tail += 1;
        }
    }
    return s;
}
