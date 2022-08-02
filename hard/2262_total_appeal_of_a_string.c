long long appealSum(char * s) {
    int previous_index_map[26] = {};
    for (size_t i = 0; i < 26; i ++) {
        previous_index_map[i] = -1;
    }
    long long result = 0, current_attract = 0;
    size_t length = strlen(s);
    for (size_t i = 0; i < length; i ++) {
        int previous_location = previous_index_map[s[i] - 'a'];
        current_attract += (i - previous_location);
        result += current_attract;
        previous_index_map[s[i] - 'a'] = i;
    }
    return result;
}
