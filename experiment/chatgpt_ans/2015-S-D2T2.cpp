#include <stdio.h>
#include <string.h>

const int MOD = 1000000007;

int n, m, k;
char a[1000005], b[1000005];
int f[1000005], g[1000005];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    scanf("%s%s", a, b);
    f[0] = 1;
    for (int i = 1, j = 0; i <= n; i++) {
        while (j && a[i-1] != b[j]) j = g[j];
        if (a[i-1] == b[j]) j++;
        g[i] = j;
        if (j == m) {
            f[i] = (f[i-m] + f[i-1]) % MOD;
        } else {
            f[i] = f[i-1];
        }
    }
    int ans = 0;
    for (int i = k*m; i <= n; i++) {
        ans = (ans + f[i]) % MOD;
    }
    printf("%d\n", ans);
    return 0;
}
