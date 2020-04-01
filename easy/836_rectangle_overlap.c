#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    int rowOverlap = MIN(rec1[2], rec2[2]) - MAX(rec1[0], rec2[0]);
    int colOverlap = MIN(rec1[3], rec2[3]) - MAX(rec1[1], rec2[1]);
    return rowOverlap > 0 && colOverlap > 0;
}
