char ** removeComments(char ** source, int sourceSize, int* returnSize) {
    bool isInBlockComment = false;
    const int maxLineCount = sourceSize;
    const int maxLineLength = 80;
    char ** resultContainer = (char**)malloc(sizeof(char*) * maxLineCount);
    int currentLineIndex = 0;
    int currentCharIndex = 0;
    for (int i = 0; i < sourceSize; i ++) {
        resultContainer[i] = (char*)malloc(sizeof(char) * maxLineLength);
        bool shouldSkip = false;
        for (int j = 0; source[i][j] != '\0'; j ++) {
            if (shouldSkip) {shouldSkip = false; continue;}
            if (!isInBlockComment && source[i][j] == '/' && source[i][j + 1] == '*') {
                isInBlockComment = true;
                shouldSkip = true;
            } else if (!isInBlockComment && source[i][j] == '/' && source[i][j + 1] == '/') {
                break;
            } else if (isInBlockComment && source[i][j] == '*' && source[i][j + 1] == '/') {
                isInBlockComment = false;
                shouldSkip = true;
            } else if (isInBlockComment) {
                continue;
            } else {
                resultContainer[currentLineIndex][currentCharIndex] = source[i][j];
                currentCharIndex ++;
            }
        }
        if (!isInBlockComment && currentCharIndex != 0) {
            resultContainer[currentLineIndex][currentCharIndex] = '\0';
            currentLineIndex ++;
            currentCharIndex = 0;
        }
    }
    *returnSize = currentLineIndex;
    return resultContainer;
}
