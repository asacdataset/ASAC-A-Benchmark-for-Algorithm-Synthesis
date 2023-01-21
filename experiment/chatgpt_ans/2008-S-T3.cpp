#include <stdio.h>
#include <string.h>

int n, m;
int arr[55][55];
int dp1[55][55], dp2[55][55];

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]) + arr[i][j];
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            dp2[i][j] = max(dp2[i + 1][j], dp2[i][j + 1]) + arr[i][j];
        }
    }
    int ans = 0;
    for (int i = 2; i < n; i++) {
        for (int j = 2; j < m; j++) {
            ans = max(ans, dp1[i - 1][j] + dp2[i + 1][j] + dp1[i][j - 1] + dp2[i][j + 1]);
        }
    }
    printf("%d", ans);
    return 0;
}
