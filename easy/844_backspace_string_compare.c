int previousCharIndex(char* s, int lastIndex) {
    int backspaceCount = 0;
    while (lastIndex >= 0) {
        if (s[lastIndex] == '#') {
            backspaceCount += 1;
        } else {
            if (backspaceCount == 0) {
                return lastIndex;
            } else {
                backspaceCount -= 1;
            }
        }
        lastIndex -= 1;
    }
    return -1;
}

bool backspaceCompare(char * s, char * t) {
    int sPreviousIndex = strlen(s) - 1, tPreviousIndex = strlen(t) - 1;
    do {
        sPreviousIndex = previousCharIndex(s, sPreviousIndex);
        tPreviousIndex = previousCharIndex(t, tPreviousIndex);
        if (sPreviousIndex == -1 && tPreviousIndex == -1) {
            return true;
        } else if (sPreviousIndex == -1 || tPreviousIndex == -1) {
            return false;
        } else if (s[sPreviousIndex] != t[tPreviousIndex]) {
            return false;
        }
        sPreviousIndex -= 1;
        tPreviousIndex -= 1;
    } while (true);
    return false;
}
