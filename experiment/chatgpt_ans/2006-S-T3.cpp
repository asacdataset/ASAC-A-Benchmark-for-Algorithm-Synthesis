#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 20
#define MAX_M 20

int m, n;
int schedule[MAX_N * MAX_M];
int machine[MAX_N][MAX_M];
int time[MAX_N][MAX_M];
int dp[MAX_N][MAX_M][MAX_N * MAX_M];

int main() {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n * m; i++) {
        scanf("%d", &schedule[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &machine[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &time[i][j]);
        }
    }

    memset(dp, -1, sizeof(dp));
    dp[0][machine[schedule[0]][0]][0] = 0;

    for (int i = 0; i < n * m; i++) {
        int op = schedule[i];
        int ma = machine[op][i % m];
        int t = time[op][i % m];
        for (int j = 0; j < m; j++) {
            for (int k = 0; k <= i; k++) {
                if (dp[i][j][k] == -1) {
                    continue;
                }
                if (j == ma) {
                    dp[i+1][j][k+t] = min(dp[i+1][j][k+t], dp[i][j][k] + t);
                } else {
                    dp[i+1][ma][k] = min(dp[i+1][ma][k], dp[i][j][k]);
                }
            }
        }
    }

    int ans = INT_MAX;
    for (int j = 0; j < m; j++) {
        for (int k = 0; k < n * m; k++) {
            ans = min(ans, dp[n * m][j][k]);
        }
    }
    printf("%d\n", ans);
    return 0;
}
