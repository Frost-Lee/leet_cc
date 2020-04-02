void depthFirstSearch(char** grid, int sourceRow, int sourceCol, int rowSize, int colSize) {
    if (sourceRow < 0 || sourceRow >= rowSize) {return;}
    if (sourceCol < 0 || sourceCol >= colSize) {return;}
    if (grid[sourceRow][sourceCol] == '0') {return;}
    grid[sourceRow][sourceCol] = '0';
    depthFirstSearch(grid, sourceRow - 1, sourceCol, rowSize, colSize);
    depthFirstSearch(grid, sourceRow + 1, sourceCol, rowSize, colSize);
    depthFirstSearch(grid, sourceRow, sourceCol - 1, rowSize, colSize);
    depthFirstSearch(grid, sourceRow, sourceCol + 1, rowSize, colSize);
}

void firstLandIndex(char **grid, int rowSize, int colSize, int* row, int* col) {
    for (int i = 0; i < rowSize; i ++) {
        for (int j = 0; j < colSize; j ++) {
            if (grid[i][j] != '0') {
                *row = i;
                *col = j;
                return;
            }
        }
    }
    *row = -1;
    *col = -1;
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    if (gridSize == 0 || * gridColSize == 0) {return 0;}
    int islandCount = 0;
    int sourceRowIndex = 0, sourceColIndex = 0;
    firstLandIndex(grid, gridSize, *gridColSize, &sourceRowIndex, &sourceColIndex);
    while (sourceRowIndex >= 0 && sourceColIndex >= 0) {
        depthFirstSearch(grid, sourceRowIndex, sourceColIndex, gridSize, *gridColSize);
        islandCount ++;
        firstLandIndex(grid, gridSize, *gridColSize, &sourceRowIndex, &sourceColIndex);
    }
    return islandCount;
}
