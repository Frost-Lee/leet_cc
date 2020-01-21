bool isPalindrome(int x){
    if (x < 0) {return false;}
    long int reverted = 0;
    long int copiedX = x;
    while (copiedX > 0) {
        reverted *= 10;
        reverted += copiedX % 10;
        copiedX /= 10;
    }
    return reverted == x;
}
