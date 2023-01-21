#include <stdio.h>
#include <string.h>

const int N = 300005;
int n, m, v[N], w[N], f[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &v[i], &w[i]);
        v[i] *= w[i];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = n; j >= v[i]; j--) {
            f[j] = max(f[j], f[j - v[i]] + v[i]);
        }
    }
    printf("%d\n", f[n]);
    return 0;
}
