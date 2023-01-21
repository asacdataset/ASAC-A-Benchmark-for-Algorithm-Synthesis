#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int n, m, p;
int gold[105][105];
int cost[105];
int dp[105][105];

int main() {
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &gold[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &cost[i]);
    }

    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= p; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][p];
            } else {
                dp[i][j] = dp[i - 1][j - 1];
            }
            for (int k = 1; k <= n; k++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + gold[k][i] - cost[k]);
            }
        }
    }

    int ans = -2147483647;
    for (int i = 0; i <= p; i++) {
        ans = max(ans, dp[m][i]);
    }
    printf("%d\n", ans);

    return 0;
}
