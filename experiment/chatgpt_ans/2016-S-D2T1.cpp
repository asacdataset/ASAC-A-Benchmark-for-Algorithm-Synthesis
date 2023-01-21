#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ll long long

ll t, k;
ll fact[100005];

ll C(int n, int m) {
    return fact[n] / (fact[m] * fact[n-m]);
}

int main() {
    scanf("%lld%lld", &t, &k);

    fact[0] = 1;
    for (int i = 1; i <= 100000; i++) fact[i] = fact[i-1] * i;

    while (t--) {
        ll n, m;
        scanf("%lld%lld", &n, &m);

        ll ans = 0;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= i && j <= m; j++)
                if (C(i, j) == k) ans++;

        printf("%lld\n", ans);
    }

    return 0;
}
