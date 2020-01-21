#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int maxArea(int* height, int heightSize) {
    int* maxList = (int*)malloc(sizeof(int) * heightSize);
    int currentMaxHeight = 0;
    for (int i = heightSize - 1; i >= 0; i --) {
        if (currentMaxHeight < height[i]) {
            currentMaxHeight = height[i];
        }
        maxList[i] = currentMaxHeight;
    }
    int currentMaxArea = 0;
    for (int i = 0; i < heightSize - 1; i ++) {
        int testIndex = i;
        while (1) {
            int oldTestIndex = testIndex;
            testIndex += 1;
            while (oldTestIndex != testIndex && testIndex < heightSize) {
                oldTestIndex = testIndex;
                if (maxList[testIndex] == 0) {
                    testIndex = heightSize;
                    break;
                }
                testIndex = MAX(testIndex, i + currentMaxArea / maxList[testIndex] + 1);
            }
            if (testIndex >= heightSize) {
                break;
            }
            currentMaxArea = MAX(currentMaxArea, (testIndex - i) * MIN(height[i], height[testIndex]));
        }
    }
    free(maxList);
    return currentMaxArea;
}
