#include <stdio.h>
#include <stdlib.h>

#define MAX_N 105
#define MAX_T 1005

int t, n, m, p[MAX_T][MAX_N], dp[MAX_T][MAX_N];

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    scanf("%d%d%d", &t, &n, &m);
    for (int i = 1; i <= t; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &p[i][j]);
    for (int i = 1; i <= t; i++)
        for (int j = 0; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            for (int k = 1; k <= n; k++)
                if (j >= p[i][k])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - p[i][k]] + p[i][k]);
        }
    printf("%d\n", dp[t][m]);
    return 0;
}
