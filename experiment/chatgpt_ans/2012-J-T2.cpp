#include <bits/stdc++.h>
using namespace std;

const int mod = 20123;
int n, m, ans, x, st[10005][105], cnt[10005];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d%d", &st[i][j], &x);
            if (st[i][j]) {
                cnt[i]++;
                ans = (ans + x) % mod;
            }
        }
    }
    scanf("%d", &x);
    for (int i = 1; i <= n; i++) {
        x = (x + cnt[i] - st[i][x]) % m;
    }
    printf("%d\n", ans);
    return 0;
}