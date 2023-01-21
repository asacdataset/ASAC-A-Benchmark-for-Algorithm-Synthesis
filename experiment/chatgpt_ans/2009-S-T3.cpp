#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 1001
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int price[MAX_N], n, m;
bool graph[MAX_N][MAX_N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &price[i]);
    }
    memset(graph, false, sizeof(graph));
    while (m--) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        graph[x][y] = z == 1 ? true : graph[x][y];
        graph[y][x] = z == 2 ? true : graph[y][x];
    }

    int dp[n + 1];
    memset(dp, -0x3f, sizeof(dp));
    dp[1] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (graph[i][j]) {
                dp[j] = max(dp[j], dp[i] + price[j] - price[i]);
            }
        }
    }

    printf("%d\n", dp[n]);
    return 0;
}
