#define MAX_LEN 2000

char * convert(char * s, int numRows) {
    if (numRows == 1) {
        return s;
    }
    char zigzagMatrix[MAX_LEN][MAX_LEN] = {};
    memset(zigzagMatrix, '\0', MAX_LEN * MAX_LEN);
    bool isVertical = true;
    bool shouldEnd = false;
    int iterationCount = 0;
    while (!shouldEnd) {
        if (isVertical) {
            for (int i = 0; i < numRows; i ++) {
                char currentChar = s[iterationCount * (numRows * 2 - 2) + i];
                if (currentChar == '\0') {
                    shouldEnd = true;
                    break;
                }
                zigzagMatrix[i][iterationCount * (numRows - 1)] = currentChar;
            }
        } else {
            for (int i = 0; i < numRows - 2; i ++) {
                char currentChar = s[iterationCount * (numRows * 2 - 2) + numRows + i];
                if (currentChar == '\0') {
                    shouldEnd = true;
                    break;
                }
                zigzagMatrix[numRows - 2 - i][iterationCount * (numRows - 1) + 1 + i] = currentChar;
            }
        }
        isVertical = !isVertical;
        if (isVertical) {
            iterationCount ++;
        }
    }
    char * result = (char*)malloc(sizeof(char) * (strlen(s) + 1));
    int collectionIndex = 0;
    for (int i = 0; i < numRows; i ++) {
        for (int j = 0; j < (iterationCount + 1) * (numRows - 1); j ++) {
            if (zigzagMatrix[i][j] != '\0') {
                result[collectionIndex] = zigzagMatrix[i][j];
                collectionIndex ++;
            }
        }
    }
    result[strlen((s))] = '\0';
    return result;
}
