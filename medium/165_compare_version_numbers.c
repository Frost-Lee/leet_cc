int readInt(char ** input) {
    int result = 0;
    if (*input[0] == '\0') {return 0;}
    while (!(*input[0] >= '0' && *input[0] <= '9')) {(*input)++;}
    while (*input[0] >= '0' && *input[0] <= '9') {
        result = result * 10 + (*input[0] - '0');
        (*input) ++;
    }
    return result;
}

int compareVersion(char * version1, char * version2) {
    while (version1[0] != '\0' || version2[0] != '\0') {
        int subVersion1 = readInt(&version1);
        int subVersion2 = readInt(&version2);
        if (subVersion1 > subVersion2) {
            return 1;
        } else if (subVersion1 < subVersion2) {
            return -1;
        }
    }
    return 0;
}
