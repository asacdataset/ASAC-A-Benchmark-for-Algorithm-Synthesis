#include <stdio.h>
#include <stdlib.h>

#define MAXN 16384

int n, d;
int x[MAXN], y[MAXN], k[MAXN];
int sum[257][257];

int main() {
    scanf("%d%d", &d, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &x[i], &y[i], &k[i]);
        x[i]++, y[i]++;
    }
    for (int i = 1; i <= n; i++) {
        sum[x[i]][y[i]] = k[i];
    }
    for (int i = 1; i <= 256; i++) {
        for (int j = 1; j <= 256; j++) {
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    int ansx = 0, ansy = 0, ans = 0;
    for (int i = 1; i <= 256 - 2 * d; i++) {
        for (int j = 1; j <= 256 - 2 * d; j++) {
            int tmp = sum[i + 2 * d][j + 2 * d] - sum[i][j + 2 * d] - sum[i + 2 * d][j] + sum[i][j];
            if (tmp > ans) {
                ans = tmp;
                ansx = i;
                ansy = j;
            }
        }
    }
    printf("%d %d\n", ansx - 1, ansy - 1);
    printf("%d\n", ans);
    return 0;
}
