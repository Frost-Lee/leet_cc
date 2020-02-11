int romanCharToInt(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(char * s) {
    if (strlen(s) == 0) {return 0;}
    int sum = 0, cacheSum = 0;
    for (int i = 0; i < strlen(s) - 1; i ++) {
        int thisValue = romanCharToInt(s[i]);
        int nextValue = romanCharToInt(s[i + 1]);
        if (nextValue > thisValue) {
            cacheSum += thisValue;
        } else {
            sum -= cacheSum;
            cacheSum = 0;
            sum += thisValue;
        }
    }
    sum -= cacheSum;
    sum += romanCharToInt(s[strlen(s) - 1]);
    return sum;
}
