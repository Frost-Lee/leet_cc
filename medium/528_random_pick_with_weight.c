double r2() {
    return (double)rand() / (double)RAND_MAX ;
}

typedef struct {
    double *percentiles;
    size_t size;
} Solution;

Solution* solutionCreate(int* w, int wSize) {
    Solution *solution = (Solution*)malloc(sizeof(Solution));
    int weight_sum = 0;
    for (int i = 0; i < wSize; i ++) {
        weight_sum += w[i];
    }
    solution->percentiles = (double *)malloc(sizeof(double) * wSize);
    solution->size = wSize;
    double percentile = 0.0;
    for (int i = 0; i < wSize; i ++) {
        percentile += (double)w[i] / (double)weight_sum;
        solution->percentiles[i] = percentile;
    }
    return solution;
}

int solutionPickIndex(Solution* obj) {
    double random_number = r2();
    int start = 0, end = obj->size - 1;
    while (start < end) {
        int middle = start + (end - start) / 2;
        if (random_number > obj->percentiles[middle]) {
            start = middle + 1;
        } else {
            end = middle;
        }
    }
    return start;
}

void solutionFree(Solution* obj) {
    if (obj == NULL) {
        return;
    }
    free(obj->percentiles);
    free(obj);
}
