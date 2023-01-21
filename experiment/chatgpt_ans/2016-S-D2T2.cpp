#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ll long long

int n, m, q, u, v, t;
ll a[100005];
ll cut[100005];
ll res[100005];

int main() {
    scanf("%d%d%d%d%d%d", &n, &m, &q, &u, &v, &t);

    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);

    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        ll maxa = -1;
        int idx = -1;
        for (int j = 1; j <= n; j++) {
            if (a[j] > maxa) {
                maxa = a[j];
                idx = j;
            }
        }
        cut[i] = maxa;
        if (i % t == 0) res[++cnt] = maxa;
        ll x = maxa / v, y = maxa % v;
        if (y * u >= v * x) a[idx] = x + 1;
        else a[idx] = x;
        a[++n] = maxa - a[idx];
        for (int j = 1; j <= n; j++) a[j] += q;
    }

    for (int i = 1; i <= cnt; i++) printf("%lld ", res[i]);
    printf("\n");

    for (int i = 1; i <= n; i++) {
        if (a[i] < 0) break;
        printf("%lld ", a[i]);
    }
    printf("\n");

    return 0;
}
