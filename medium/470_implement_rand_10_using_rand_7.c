int rand10() {
    int row, col;
    bool is_generated = false;
    while (!is_generated) {
        row = rand7() - 1;
        col = rand7() - 1;
        is_generated = row * 7 + col < 40;
    }
    return (row * 7 + col) % 10 + 1;
}
