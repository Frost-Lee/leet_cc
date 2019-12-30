#define MAX_LEN 1000

char * longestPalindrome(char * s) {
    if (strlen(s) == 0 || strlen((s)) == 1) {
        return s;
    }
    int stages[MAX_LEN][MAX_LEN] = {0};
    int start = 0, end = 0;
    for (int i = 0; i < strlen(s) - 1; i ++) {
        stages[i + 1][i] = 1;
    }
    for (int i = 0; i < strlen(s); i ++) {
        for (int j = 0; j < strlen(s) - i; j ++) {
            if (i == 0 || (s[j] == s[i + j] && stages[j + 1][i + j - 1] != 0)) {
                stages[j][i + j] = 1;
                start = j;
                end = i + j;
            }
        }
    }
    char * result = (char*)malloc(sizeof(char) * (end - start + 2));
    result[end - start + 1] = '\0';
    strncpy(result, s + start, end - start + 1);
    return result;
}
