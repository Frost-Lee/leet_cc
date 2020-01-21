int myAtoi(char * str) {
    int converted = 0;
    bool shouldRevert = false;
    bool parseBegun = false;
    for (int i = 0; i < (int)strlen(str); i ++) {
        switch (str[i]) {
            case ' ':
                if (parseBegun) {return converted;}
                break;
            case '+': case '-':
                if (parseBegun) {return converted;}
                parseBegun = true;
                if (str[i] == '-') {shouldRevert = !shouldRevert;}
                break;
            default:
                if (str[i] - '0' >= 0 && str[i] - '0' <= 9) {
                    int newDigit = (int)(str[i] - '0');
                    if ((converted > INT_MAX / 10 || (converted == INT_MAX / 10 && newDigit > 7))) {return INT_MAX;}
                    if ((converted < INT_MIN / 10 || (converted == INT_MIN / 10 && newDigit > 8))) {return INT_MIN;}
                    parseBegun = true;
                    converted *= 10;
                    converted += shouldRevert ? -newDigit : newDigit;
                } else {return converted;}
        }
    }
    return converted;
}
