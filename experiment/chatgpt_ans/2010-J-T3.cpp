#include <stdio.h>
#include <math.h>

int main() {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    int N;
    scanf("%d", &N);
    int minCost = 0;
    for (int i = 0; i < N; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        int distance1 = (x - x1) * (x - x1) + (y - y1) * (y - y1);
        int distance2 = (x - x2) * (x - x2) + (y - y2) * (y - y2);
        minCost += fmin(distance1, distance2);
    }
    printf("%d", minCost);
    return 0;
}
