int characterReplacement(char * s, int k) {
    short hashmap[26] = {};
    int head = 0;
    int max_length = 0, max_occurance = 0;
    for (int i = 0; i < strlen(s); i ++) {
        hashmap[s[i] - 'A'] += 1;
        max_occurance = fmax(max_occurance, hashmap[s[i] - 'A']);
        if (i - head + 1 - max_occurance > k) {
            hashmap[s[head] - 'A'] -= 1;
            head += 1;
        }
        max_length = fmax(max_length, i - head + 1);
    }
    return max_length;
}
