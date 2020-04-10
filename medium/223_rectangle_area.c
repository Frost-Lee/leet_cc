#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

long int boxArea(long int x1, long int y1, long int x2, long int y2) {
    if (x2 < x1 || y2 < y1) {
        return 0;
    } else {
        return (x2 - x1) * (y2 - y1);
    }
}

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    long int intersectionArea = boxArea(MAX(A, E), MAX(B, F), MIN(C, G), MIN(D, H));
    printf("%d\n", intersectionArea);
    long int unionArea = boxArea(A, B, C, D) + boxArea(E, F, G, H) - intersectionArea;
    return unionArea;
}
