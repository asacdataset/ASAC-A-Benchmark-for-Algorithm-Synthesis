#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100
#define MAX_M 100

int n, m;
int v[MAX_N + 1], p[MAX_N + 1], q[MAX_N + 1];
int dp[MAX_N + 1][MAX_M + 1];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &v[i], &p[i], &q[i]);
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (q[i] == 0) {
                dp[i][j] = dp[i-1][j];
                if (j >= v[i]) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-v[i]] + v[i] * p[i]);
                }
            } else {
                if (dp[q[i]-1][j] != -1) {
                    dp[i][j] = dp[q[i]-1][j];
                    if (j >= v[i]) {
                        dp[i][j] = max(dp[i][j], dp[q[i]-1][j-v[i]] + v[i] * p[i]);
                    }
                } else {
                    dp[i][j] = -1;
                }
            }
        }
    }
    printf("%d\n", dp[m][n]);
    return 0;
}
