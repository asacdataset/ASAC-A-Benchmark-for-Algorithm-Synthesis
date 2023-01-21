#include <stdio.h>

const int mod = 10007;

int main() {
    int l;
    scanf("%d", &l);

    char expr[100001];
    scanf("%s", expr);

    int dp[100001][2];
    dp[0][0] = 1;
    dp[0][1] = 0;

    for (int i = 0; i < l; i++) {
        if (expr[i] == '(') {
            dp[i + 1][0] = 0;
            dp[i + 1][1] = 0;
        } else if (expr[i] == ')') {
            dp[i + 1][0] = dp[i - 1][0] * dp[i][0] % mod;
            dp[i + 1][1] = dp[i - 1][1] * dp[i][1] % mod;
        } else if (expr[i] == '+') {
            dp[i + 1][0] = (dp[i][0] * dp[i][1] % mod) + (dp[i][1] * dp[i][0] % mod);
            dp[i + 1][1] = (dp[i][1] * dp[i][1] % mod);
        } else if (expr[i] == '*') {
            dp[i + 1][0] = dp[i][0] * dp[i][0] % mod;
            dp[i + 1][1] = (dp[i][0] * dp[i][1] % mod) + (dp[i][1] * dp[i][1] % mod);
        }
        dp[i + 1][0] %= mod;
        dp[i + 1][1] %= mod;
    }

    printf("%d", dp[l][0]);

    return 0;
}