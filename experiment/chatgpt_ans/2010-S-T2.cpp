#include <stdio.h>

int n, m;
int a[1005];
int b[1005];
int dp[1005];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i - b[j] >= 0) {
                dp[i] = dp[i] > dp[i-b[j]] + a[i] ? dp[i] : dp[i-b[j]] + a[i];
            }
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
