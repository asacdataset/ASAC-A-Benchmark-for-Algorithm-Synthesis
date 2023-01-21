#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1005;
int n, m, k;
int d[MAXN], t[MAXN], a[MAXN], b[MAXN];
int f[MAXN][MAXN];

int main() {
    cin >> n >> m >> k;
    for (int i = 2; i <= n; i++) {
        cin >> d[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> t[i] >> a[i] >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            f[i][j] = INF;
        }
    }
    f[1][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (f[i][j] != INF) {
                for (int l = i + 1; l <= n; l++) {
                    f[l][j] = min(f[l][j], f[i][j] + d[l]);
                    if (j < k) {
                        f[l][j + 1] = min(f[l][j + 1], f[i][j] + max(0, d[l] - 1));
                    }
                }
            }
        }
    }

    int ans = INF;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= k; j++) {
            ans = min(ans, t[i] + f[b[i]][j] - f[a[i]][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
