#include <stdio.h>
#include <stdlib.h>

int main() {
    int w, n, i, j;
    scanf("%d%d", &w, &n);
    int p[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    int dp[n+1][w+1];
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= w; j++) {
            dp[i][j] = 0;
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= w; j++) {
            if (p[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-p[i-1]];
            }
        }
    }

    int min_groups = 0;
    for (i = w; i >= 0; i--) {
        if (dp[n][i] > 0) {
            min_groups = (w - i) / 2;
            break;
        }
    }

    printf("%d", min_groups);
    return 0;
}
