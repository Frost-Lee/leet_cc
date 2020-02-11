char * longestCommonPrefix(char ** strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    } else if (strsSize == 1) {
        return strs[0];
    }
    int resultSize = 16;
    char * result = (char*)malloc(sizeof(char) * resultSize);
    int prefixSize = 0;
    while (1) {
        int shouldBreak = 0;
        for (int i = 1; i < strsSize; i ++) {
            if (strlen(strs[i - 1]) <= prefixSize || strlen(strs[i]) <= prefixSize || strs[i][prefixSize] != strs[i - 1][prefixSize]) {
                shouldBreak = 1;
                break;
            }
        }
        if (shouldBreak) {break;}
        result[prefixSize] = strs[0][prefixSize];
        prefixSize += 1;
        if (prefixSize >= resultSize) {
            resultSize *= 2;
            result = (char*)realloc(result, sizeof(char) * resultSize);
        }
    }
    result[prefixSize] = '\0';
    return result;
}
