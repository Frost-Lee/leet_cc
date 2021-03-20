bool checkInclusion(char * s1, char * s2) {
    unsigned short s1_char_summary[26] = {}, s2_char_summary[26] = {};
    if (strlen(s2) < strlen(s1)) {
        return false;
    }
    for (int i = 0; i < strlen(s1); i ++) {
        s1_char_summary[s1[i] - 'a'] += 1;
        s2_char_summary[s2[i] - 'a'] += 1;
    }
    int different_count = 0;
    for (int i = 0; i < 26; i ++) {
        if (s1_char_summary[i] != s2_char_summary[i]) {
            different_count += 1;
        }
    }
    for (int i = strlen(s1); i < strlen(s2); i ++) {
        if (different_count == 0) {
            break;
        }
        int new_char_index = s2[i] - 'a';
        int old_char_index = s2[i - strlen(s1)] - 'a';
        if (s1_char_summary[old_char_index] == s2_char_summary[old_char_index]) {
            different_count += 1;
        } else if (s1_char_summary[old_char_index] == s2_char_summary[old_char_index] - 1) {
            different_count -= 1;
        }
        s2_char_summary[old_char_index] -= 1;
        if (s1_char_summary[new_char_index] == s2_char_summary[new_char_index]) {
            different_count += 1;
        } else if (s1_char_summary[new_char_index] == s2_char_summary[new_char_index] + 1) {
            different_count -= 1;
        }
        
        s2_char_summary[new_char_index] += 1;
    }
    return different_count == 0;
}
