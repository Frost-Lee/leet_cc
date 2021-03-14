int lengthOfLongestSubstring(char * s) {
    short hashmap[128] = {};
    int head = 0, max_length = 0;
    for (int i = 0; i < strlen(s); i ++) {
        while (hashmap[s[i]] != 0) {
            hashmap[s[head]] = 0;
            head += 1;
        }
        hashmap[s[i]] = 1;
        max_length = fmax(max_length, i - head + 1);
    }
    return max_length;
}
