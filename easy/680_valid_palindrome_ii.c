bool check_palindrome(char *s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start += 1;
        end -= 1;
    }
    return true;
}

bool validPalindrome(char * s) {
    int start = 0, end = (int)strlen(s) - 1;
    while (start < end) {
        if (s[start] != s[end]) {
            return check_palindrome(s, start + 1, end) || check_palindrome(s, start, end - 1);
        }
        start += 1;
        end -= 1;
    }
    return true;
}
