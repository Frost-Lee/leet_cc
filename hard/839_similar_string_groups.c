bool is_similar(char *lhs, char *rhs) {
    if (strlen(lhs) != strlen(rhs)) {
        return false;
    }
    bool is_swapped = false;
    bool is_swapping = false;
    char lhs_swap, rhs_swap;
    for (size_t i = 0; i < strlen(lhs); i ++) {
        if (lhs[i] != rhs[i]) {
            if (is_swapped) {
                return false;
            } else if (is_swapping) {
                if (lhs_swap == rhs[i] && rhs_swap == lhs[i]) {
                    is_swapped = true;
                    is_swapping = false;
                } else {
                    return false;
                }
            } else {
                lhs_swap = lhs[i];
                rhs_swap = rhs[i];
                is_swapping = true;
            }
        }
    }
    return true;
}

size_t find(int *disjoint_set, size_t index) {
    while (disjoint_set[index] >= 0) {
        index = disjoint_set[index];
    }
    return index;
}

void set_union(int *disjoint_set, size_t index_1, size_t index_2) {
    if (disjoint_set[index_1] < disjoint_set[index_2]) {
        size_t temp = index_1;
        index_1 = index_2;
        index_2 = temp;
    }
    int size = -disjoint_set[index_1];
    disjoint_set[index_1] = index_2;
    disjoint_set[index_2] -= size;
}

int numSimilarGroups(char ** strs, int strsSize) {
    int *disjoint_set = (int *)malloc(sizeof(int) * strsSize);
    for (size_t i = 0; i < strsSize; i ++) {
        disjoint_set[i] = -1;
    }
    for (size_t i = 0; i < strsSize; i ++) {
        for (size_t j = i + 1; j < strsSize; j ++) {
            if (is_similar(strs[i], strs[j])) {
                size_t group_i = find(disjoint_set, i);
                size_t group_j = find(disjoint_set, j);
                if (group_i != group_j) {
                    set_union(disjoint_set, group_i, group_j);
                }
            }
        }
    }
    int similar_group_count = 0;
    for (size_t i = 0; i < strsSize; i ++) {
        if (disjoint_set[i] < 0) {
            similar_group_count += 1;
        }
    }
    free(disjoint_set);
    return similar_group_count;
}
