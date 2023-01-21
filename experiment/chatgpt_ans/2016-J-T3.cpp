#include <stdio.h>
#include <string.h>

const int MAXN = 3e5 + 5;
const int MAXK = 1e5 + 5;

int n, m, k[MAXN], x[MAXN][MAXK], cnt[MAXK], ans[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &m, &k[i]);
        for (int j = 0; j < k[i]; j++) {
            scanf("%d", &x[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k[i]; j++) {
            if (m - k[i] < 86400) {
                cnt[x[i][j]]++;
            }
        }
        int res = 0;
        for (int j = 1; j <= MAXK; j++) {
            if (cnt[j]) {
                res++;
            }
        }
        ans[i] = res;
        for (int j = 0; j < k[i]; j++) {
            if (m - k[i] >= 86400) {
                cnt[x[i][j]] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
