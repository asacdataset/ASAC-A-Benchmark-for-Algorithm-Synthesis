#include <stdio.h>
#include <string.h>

#define MOD 1000000007
#define MAX_N 101

int n, m;
int dp[MAX_N][MAX_N];

int main() {
    scanf("%d%d", &n, &m);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }
    printf("%d", dp[n][m]);
    return 0;
}
