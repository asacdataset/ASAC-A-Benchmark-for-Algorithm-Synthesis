#include <stdio.h>

int main() {
    int n, k, p;
    scanf("%d %d %d", &n, &k, &p);

    int color[100001];
    int charge[100001];
    for (int i = 1; i <= n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        color[i] = a;
        charge[i] = b;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (charge[i] > p) continue;
        for (int j = i + 1; j <= n; j++) {
            if (color[i] != color[j]) continue;
            if (charge[j] > p) continue;
            int cnt = 0;
            for (int k = i; k <= j; k++) {
                if (charge[k] <= p) cnt++;
            }
            ans += cnt - 1;
        }
    }

    printf("%d", ans);

    return 0;
}