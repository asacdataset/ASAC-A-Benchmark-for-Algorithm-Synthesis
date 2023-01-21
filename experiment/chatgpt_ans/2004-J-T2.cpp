#include <stdio.h>

#define MAX_PEANUTS 500
#define MAX_TIME 1000

int m, n, k, peanuts[25][25], max_peanuts;

void dfs(int x, int y, int time, int picked) {
    if (time > k) return; // stop if out of time
    if (x == m) { // if back on the roadside
        if (picked > max_peanuts) max_peanuts = picked; // update max
        return;
    }
    if (y == n) { // if at the end of the row
        dfs(x+1, 0, time+1, picked); // move to the next row
        return;
    }
    dfs(x, y+1, time+1, picked); // move to the next column
    if (peanuts[x][y] > 0) { // if there are peanuts in the plant
        dfs(x, y+1, time+1, picked+peanuts[x][y]); // pick the peanuts
    }
}

int main() {
    scanf("%d %d %d", &m, &n, &k);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &peanuts[i][j]);
        }
    }
    dfs(0, 0, 0, 0);
    printf("%d\n", max_peanuts);
    return 0;
}
