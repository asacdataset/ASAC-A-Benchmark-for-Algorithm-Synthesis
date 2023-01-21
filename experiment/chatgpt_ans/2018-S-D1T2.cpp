#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 1000

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int T, n, a[MAX_N], i, j;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int ans = a[0];
        for (i = 1; i < n; i++)
            ans = lcm(ans, a[i]);
        printf("%d\n", ans);
    }
    return 0;
}
