#include <stdio.h>
#include <stdlib.h>

#define MAX_N 105
#define MAX_M 105

int n, m;
int matrix[MAX_N][MAX_M];
int dp[MAX_N][MAX_M];

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[j][i] = max(dp[j][i-1], dp[j-1][i-1] + matrix[j][i] * (1 << (i-1)));
            dp[j][i] = max(dp[j][i], dp[j+1][i-1] + matrix[j][i] * (1 << (i-1)));
        }
    }

    printf("%d\n", dp[1][m]);

    return 0;
}
