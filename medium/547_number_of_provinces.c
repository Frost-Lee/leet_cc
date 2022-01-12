size_t djs_find(int *djs, size_t djs_size, size_t target) {
    if (djs[target] < 0) {
        return target;
    } else {
        return djs_find(djs, djs_size, djs[target]);
    }
}

void djs_union(int *djs, size_t djs_size, size_t target_1, size_t target_2) {
    if (target_1 == target_2){
        return;
    }
    if (target_1 > target_2) {
        djs_union(djs, djs_size, target_2, target_1);
    } else {
        djs[target_2] += djs[target_1];
        djs[target_1] = target_2;
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int *djs = (int *)malloc(sizeof(int) * isConnectedSize);
    for (size_t i = 0; i < isConnectedSize; i ++) {
        djs[i] = -1;
    }
    for (size_t i = 0; i < isConnectedSize; i ++) {
        for (size_t j = i + 1; j < isConnectedSize; j ++) {
            if (isConnected[i][j]) {
                djs_union(djs, isConnectedSize, djs_find(djs, isConnectedSize, i), djs_find(djs, isConnectedSize, j));
            }
        }
    }
    int result = 0;
    for (size_t i = 0; i < isConnectedSize; i ++) {
        if (djs[i] < 0) {
            result += 1;
        }
    }
    return result;
}
