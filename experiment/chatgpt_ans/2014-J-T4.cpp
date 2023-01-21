#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAXN = 2005;

int n, m, r, c, ans = 1e9;
int a[MAXN][MAXN], pre[MAXN][MAXN];

int main() {
    scanf("%d%d%d%d", &n, &m, &r, &c);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
        }
    }
    for (int i = r; i <= n; i++) {
        for (int j = c; j <= m; j++) {
            for (int x = i - r + 1; x <= i; x++) {
                for (int y = j - c + 1; y <= j; y++) {
                    ans = min(ans, pre[i][j] - pre[x - 1][j] - pre[i][y - 1] + pre[x - 1][y - 1]);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
