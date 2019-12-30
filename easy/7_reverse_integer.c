int reverse(int x) {
    int reversed = 0;
    while (x != 0) {
        int newFigure = x % 10;
        if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && newFigure > 7)) {return 0;}
        if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && newFigure < -8)) {return 0;}
        reversed *= 10;
        reversed += newFigure;
        x /= 10;
    }
    return reversed;
}