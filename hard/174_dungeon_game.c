#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int calculateMinimumHP(int** dungeon, int dungeonSize, int* dungeonColSize) {
    int* dpArray = (int*)malloc(sizeof(int) * (dungeonSize + 1) * (*dungeonColSize + 1));
    for (int i = 0; i < (dungeonSize + 1) * (*dungeonColSize + 1); i ++) {
        dpArray[i] = INT_MAX;
    }
    dpArray[(*dungeonColSize + 1) * dungeonSize + *dungeonColSize - 1] = 1;
    dpArray[(*dungeonColSize + 1) * (dungeonSize - 1) + *dungeonColSize] = 1;
    for (int i = dungeonSize - 1; i >= 0; i --) {
        for (int j = *dungeonColSize - 1; j >= 0; j --) {
            dpArray[(*dungeonColSize + 1) * i + j] = MAX(1,MIN(dpArray[(*dungeonColSize + 1) * (i + 1) + j], dpArray[(*dungeonColSize + 1) * i + (j + 1)]) - dungeon[i][j]);
        }
    }
    int result = dpArray[0];
    free(dpArray);
    return result;
}