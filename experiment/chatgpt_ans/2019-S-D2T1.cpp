#include <stdio.h>
#include <algorithm>

const int mod = 998244353;

int n, m;
int a[505][505];
int sum[505];
int dp[505][505];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
            sum[j] += a[i][j];
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j >= 1; j--) {
            for (int k = std::min(j, (sum[i] + 1) / 2); k >= 1; k--) {
                dp[j][k] = (dp[j][k] + 1ll * dp[j - 1][k - 1] * a[i][j]) % mod;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + dp[i][i]) % mod;
    }
    printf("%d\n", ans);
    return 0;
}
