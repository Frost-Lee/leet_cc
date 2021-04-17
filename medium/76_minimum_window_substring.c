char * minWindow(char * s, char * t) {
    if (strlen(s) < strlen(t)) {
        return "\0";
    }
    int hash_table_length = 128;
    int counter_size = sizeof(unsigned short) * hash_table_length;
    unsigned short * s_counter = (unsigned short*)malloc(counter_size);
    unsigned short * t_counter = (unsigned short*)malloc(counter_size);
    memset(s_counter, 0, counter_size);
    memset(t_counter, 0, counter_size);
    for (int i = 0; i < strlen(t); i ++) {
        s_counter[s[i]] += 1;
        t_counter[t[i]] += 1;
    }
    int window_start = 0, window_end = 0;
    int missing_count = -1;
    int min_match_start = -1, min_match_end = -1;
    for (int i = 0; i < strlen(s) - strlen(t) + 1; i ++) {
        window_end = i + strlen(t) - 1;
        char next_index = s[window_end];
        if (missing_count >= 0) {
            if (s_counter[next_index] == t_counter[next_index] - 1) {
                missing_count -= 1;
            }
            s_counter[next_index] += 1;
            while (s_counter[s[window_start]] > t_counter[s[window_start]]) {
                s_counter[s[window_start]] -= 1;
                window_start += 1;
            }
        } else {
            missing_count = 0;
            for (int j = 0; j < hash_table_length; j ++) {
                missing_count += s_counter[j] >= t_counter[j] ? 0 : 1;
            }
        }
        if (missing_count == 0) {
            if (window_end - window_start < min_match_end - min_match_start || min_match_start < 0) {
                min_match_start = window_start;
                min_match_end = window_end;
            }
        }
    }
    if (min_match_start < 0) {
        return "\0";
    } else {
        char* result = (char*)malloc(sizeof(char) * (min_match_end - min_match_start + 2));
        memcpy(result, s + min_match_start, sizeof(char) * (min_match_end - min_match_start + 1));
        result[min_match_end - min_match_start + 1] = '\0';
        return result;
    }
}
