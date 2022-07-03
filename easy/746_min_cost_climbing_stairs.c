int minCostClimbingStairs(int* cost, int costSize) {
    int current = 0, previous = 0, next_previous = 0;
    for (size_t i = 0; i < costSize; i ++) {
        next_previous = previous;
        previous = current;
        current = previous > next_previous ? next_previous : previous;
        current += cost[i];
    }
    return current > previous ? previous : current;
}
