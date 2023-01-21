#include <stdio.h>

#define MAX_HERBS 110

int t, m;
int time[MAX_HERBS], value[MAX_HERBS];
int dp[MAX_HERBS][MAX_HERBS];

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    scanf("%d%d", &t, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &time[i], &value[i]);
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= t; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= time[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - time[i]] + value[i]);
            }
        }
    }

    printf("%d\n", dp[m][t]);
    return 0;
}
