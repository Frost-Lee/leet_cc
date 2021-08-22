int compare(const void *a, const void *b) {
    return (*(int **)a)[0] > (*(int **)b)[0];
}

void exchange(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize){
    qsort(intervals, intervalsSize, sizeof(int *), compare);
    int roomCount = 0, capacity = 4;
    int *roomEndTimes = (int *)calloc(capacity, sizeof(int));
    for (int i = 0; i < intervalsSize; i ++) {
        if (roomCount >= 1 && roomEndTimes[1] <= intervals[i][0]) {
            roomEndTimes[1] = intervals[i][1];
            int index = 1;
            while (index * 2 <= roomCount) {
                int childIndex = index * 2;
                if (childIndex + 1 <= roomCount && roomEndTimes[childIndex + 1] < roomEndTimes[childIndex]) {
                    childIndex += 1;
                }
                if (roomEndTimes[index] > roomEndTimes[childIndex]) {
                    exchange(roomEndTimes + index, roomEndTimes + childIndex);
                    index = childIndex;
                } else {
                    break;
                }
            }
        } else {
            if (roomCount + 1 >= capacity) {
                capacity *= 2;
                roomEndTimes = realloc(roomEndTimes, sizeof(int) * capacity);
            }
            roomEndTimes[++ roomCount] = intervals[i][1];
            int index = roomCount;
            while (index / 2 > 0) {
                int parentIndex = index / 2;
                if (roomEndTimes[parentIndex] > roomEndTimes[index]) {
                    exchange(roomEndTimes + parentIndex, roomEndTimes + index);
                    index = parentIndex;
                } else {
                    break;
                }
            }
        }
    }
    free(roomEndTimes);
    return roomCount;
}
