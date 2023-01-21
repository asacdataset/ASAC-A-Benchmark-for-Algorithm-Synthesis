#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1005
#define MAXK 105
#define MAXM 5

int n, m, k;
int x[MAXN], y[MAXN];
int p[MAXK], l[MAXK], h[MAXK];
int f[MAXN][MAXM];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }
    for (int i = 1; i <= k; i++) {
        scanf("%d%d%d", &p[i], &l[i], &h[i]);
    }
    memset(f, -1, sizeof(f));
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (f[i - 1][j] != -1) {
                if (j + x[i] <= m) f[i][j + x[i]] = f[i - 1][j];
                if (j - y[i] >= 0) f[i][j - y[i]] = f[i - 1][j];
            }
        }
        for (int j = 0; j < i; j++) {
            if (f[j][l[i]] != -1) {
                if (f[i][h[i]] == -1 || f[i][h[i]] > f[j][l[i]] + i - j - 1) {
                    f[i][h[i]] = f[j][l[i]] + i - j - 1;
                }
            }
        }
    }
    int ans = -1, ansx = -1;
    for (int i = 0; i <= m; i++) {
        if (f[n][i] != -1) {
            if (ans == -1 || ans > f[n][i]) {
                ans = f[n][i];
                ansx = i;
            }
        }
    }
    if (ans == -1) {
        printf("0\n");
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (l[i] <= ansx && ansx <= h[i]) cnt++;
        }
        printf("%d\n", cnt);
    } else {
        printf("1\n%d\n", ans);
    }
    return 0;
}
