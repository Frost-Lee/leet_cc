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

int numIslands(char** grid, int gridSize, int* gridColSize){
    int islandCount = 0;
    for (int i = 0; i < gridSize; i ++) {
        for (int j = 0; j < *gridColSize; j ++) {
            if (grid[i][j] == '1') {
                depthFirstSearch(grid, i, j, gridSize, *gridColSize);
                islandCount ++;
            }
        }
    }
    return islandCount;
}
