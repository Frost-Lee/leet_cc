int largestVariance(char * s) {
    int result = 0;
    for (char i = 'a'; i <= 'z'; i ++) {
        for (char j = 'a'; j <= 'z'; j ++) {
            size_t length = strlen(s);
            int local_variance = 0;
            bool has_b = false, first_b = false;
            for (size_t k = 0; k < length; k ++) {
                if (s[k] == i) {
                    local_variance += 1;
                } else if (s[k] == j) {
                    has_b = true;
                    if (first_b && local_variance >= 0) {
                        first_b = false;
                        continue;
                    }
                    local_variance -= 1;
                    if (local_variance < 0) {
                        first_b = true;
                        local_variance = -1;
                    }
                }
                result = has_b && local_variance > result ? local_variance : result;
            }
        }
    }
    return result;
}
