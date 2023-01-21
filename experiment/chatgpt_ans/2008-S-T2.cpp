#include <stdio.h>

int matchsticks[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int dp[25];

int main() {
    int n;
    scanf("%d", &n);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            if (i >= matchsticks[j]) {
                dp[i] += dp[i - matchsticks[j]];
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            int k = n - i - j - 2;
            if (k >= 0) {
                ans += dp[i] * dp[j] * dp[k];
            }
        }
    }
    printf("%d", ans);
    return 0;
}
