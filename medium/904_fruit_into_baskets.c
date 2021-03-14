struct FruitSeries {
    int type;
    int head;
    int tail;
};

void swap(struct FruitSeries *a, struct FruitSeries *b) {
    struct FruitSeries temp = *a;
    *a = *b;
    *b = temp;
}

int totalFruit(int* tree, int treeSize) {
    int max_fruit = 1;
    struct FruitSeries series_a = {.type = tree[0], .head = 0, .tail = 0};
    struct FruitSeries series_b = {.type = -1, .head = 0, .tail = 0};
    for (int i = 1; i < treeSize; i ++) {
        struct FruitSeries * corresponding_series = NULL;
        if (tree[i] == series_a.type || tree[i] == series_b.type) {
            if (tree[i] == series_b.type) {
                swap(&series_a, &series_b);
            }
            series_a.tail = i;
        } else if (series_b.type == -1) {
            series_b.type = tree[i];
            series_b.head = i;
            series_b.tail = i;
        } else {
            if (series_a.tail > series_b.tail) {
                swap(&series_a, &series_b);
            }
            series_b.head = series_a.tail + 1;
            series_a.type = tree[i];
            series_a.head = i;
            series_a.tail = i;
        }
        max_fruit = fmax(max_fruit, i - fmin(series_a.head, series_b.head) + 1);
    }
    return max_fruit;
}
