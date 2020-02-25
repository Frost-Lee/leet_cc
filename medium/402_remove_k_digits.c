#define MAX(a,b) ((a) > (b) ? (a) : (b))

char * removeKdigits(char * num, int k) {
    char * zeroResult = (char*)malloc(sizeof(char) * 2);
    zeroResult[0] = '0';
    zeroResult[1] = '\0';
    if (k >= strlen(num)) {return zeroResult;}
    int lastIndex = 1;
    for (int i = 0; i < k; i ++) {
        for (int j = MAX(lastIndex, 1); j <= strlen(num); j ++) {
            if (num[j] < num[j - 1]) {
                lastIndex = j - 2;
                memmove(num + j - 1, num + j, strlen(num) - j + 1);
                break;
            }
        }
    }
    int zeroPrefixIndex = 0;
    for (zeroPrefixIndex = 0; num[zeroPrefixIndex] == '0' && zeroPrefixIndex < strlen(num); zeroPrefixIndex ++) {}
    if (zeroPrefixIndex < strlen(num)) {
        free(zeroResult);
        return num + zeroPrefixIndex;
    } else {
        return zeroResult;
    }
}
