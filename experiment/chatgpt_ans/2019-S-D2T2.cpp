#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

const int N = 2005;

int n, type;
int a[N], s[N];

int dp[N][N];

int main() {
    scanf("%d%d", &n, &type);
    if (type == 0) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            s[i] = s[i - 1] + a[i];
        }
    } else {
        int x, y, z, b1, b2, m;
        scanf("%d%d%d%d%d%d", &x, &y, &z, &b1, &b2, &m);
        for (int i = 3; i <= n; i++) {
            b1 = (1ll * x * b1 + 1ll * y * b2 + z) % (1 << 30);
            b2 = (1ll * x * b2 + 1ll * y * b1 + z) % (1 << 30);
        }
        int p = 0, l, r;
        for (int i = 1; i <= m; i++) {
            scanf("%d%d%d", &p, &l, &r);
            for (int j = p; j <= min(n, p + r - l); j++) {
                a[j] = (b1 % (r - l + 1)) + l;
                b1 = (1ll * x * b1 + 1ll * y * b2 + z) % (1 << 30);
                b2 = (1ll * x * b2 + 1ll * y * b1 + z) % (1 << 30);
            }
        }
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + a[i];
        }
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = j; k < i; k++) {
                dp[i][k] = min(dp[i][k], dp[j][j] + (s[i] - s[j]) * (s[i] - s[j]));
            }
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < n; i++) {
        ans = min(ans, dp[n][i]);
    }
    printf("%d\n", ans);
    return 0;
}
