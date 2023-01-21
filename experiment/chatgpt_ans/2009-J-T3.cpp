#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, m1, m2, S, minTime = -1;
    scanf("%d %d %d", &N, &m1, &m2);
    int M = m1 * m2;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &S);
        int time = 0;
        int cells = 1;
        while (cells < M) {
            cells *= S;
            time++;
        }
        if (cells == M) {
            if (minTime == -1 || time < minTime) {
                minTime = time;
            }
        }
    }
    printf("%d", minTime);
    return 0;
}
