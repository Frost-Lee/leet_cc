char * reverseWords(char * s) {
    char * copiedString = (char*)malloc(sizeof(char) * (strlen(s) + 1));
    int currentIndex = 0;
    for (int i = (int)strlen(s) - 1; i >= 0; i --) {
        if (s[i] == ' ' && (currentIndex == 0 || s[i + 1] == ' ')) {
            continue;
        } else {
            copiedString[currentIndex ++] = s[i];
        }
    }
    if (currentIndex == 0) {return "";}
    if (copiedString[currentIndex - 1] == ' ') {
        copiedString[currentIndex - 1] = '\0';
    } else {
        copiedString[currentIndex] = '\0';
    }
    int wordStartIndex = 0;
    for (int i = 0; i <= strlen(copiedString); i ++) {
        if (copiedString[i] == ' ' || copiedString[i] == '\0') {
            int wordEndIndex = i - 1;
            while (wordStartIndex < wordEndIndex) {
                char temp = copiedString[wordStartIndex];
                copiedString[wordStartIndex ++] = copiedString[wordEndIndex];
                copiedString[wordEndIndex --] = temp;
            }
            wordStartIndex = i + 1;
        }
    }
    return copiedString;
}
