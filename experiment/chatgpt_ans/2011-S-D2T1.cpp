#include <stdio.h>

#define MOD 10007

int C(int n, int m) {
    int res = 1;
    for (int i = 1; i <= m; i++) {
        res = (long long)res * (n - i + 1) / i % MOD;
    }
    return res;
}

int main() {
    int a, b, k, n, m;
    scanf("%d %d %d %d %d", &a, &b, &k, &n, &m);
    printf("%d\n", (long long)C(n, n - m) * C(k, m) % MOD * a % MOD * b % MOD);
    return 0;
}