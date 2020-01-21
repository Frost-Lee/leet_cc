bool isMatch(char * s, char * p) {
    if (strlen(s) == 0 && strlen(p) == 0) {return true;}
    if (strlen(s) == 0 && p[1] == '*') {return isMatch(s, p + 2);}
    if (strlen(s) == 0 || strlen(p) == 0) {return false;}
    if (p[1] != '*') {
        if (p[0] == '.') {
            return isMatch(s + 1, p + 1);
        } else {
            if (s[0] == p[0]) {
                return isMatch(s + 1, p + 1);
            } else {
                return false;
            }
        }
    } else {
        if (p[0] == '.' || s[0] == p[0]) {
            return isMatch(s + 1, p) || isMatch(s + 1, p + 2) || isMatch(s, p + 2);
        } else {
            return isMatch(s, p + 2);
        }
    }
}
