#include <stdio.h>

int n, a[105], dp[105], ans;

int main() {
    int i, j;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 1; i <= n; i++) {
        dp[i] = 1;
        for (j = 1; j < i; j++) {
            if (a[j] > a[i]) {
                dp[i] = dp[j] + 1 > dp[i] ? dp[j] + 1 : dp[i];
            }
        }
        ans = ans > dp[i] ? ans : dp[i];
    }
    printf("%d\n", n - ans);
    return 0;
}
