#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n, d, k, x[MAXN], s[MAXN], f[MAXN];

bool check(int g) {
    for (int i = 0; i <= n; i++) f[i] = -1e9;
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (x[i] - x[j] <= d + g && x[i] - x[j] >= d - g) {
                f[i] = max(f[i], f[j] + s[i]);
            }
        }
    }
    return f[n] >= k;
}

int main() {
    scanf("%d%d%d", &n, &d, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &x[i], &s[i]);
    }
    int l = 0, r = 1e9, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
