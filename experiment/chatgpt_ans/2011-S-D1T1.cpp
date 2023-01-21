#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    struct carpet {
        int x1, y1, x2, y2;
    } carpets[100001];

    for (int i = 1; i <= n; i++) {
        int a, b, g, k;
        scanf("%d %d %d %d", &a, &b, &g, &k);
        carpets[i].x1 = a;
        carpets[i].y1 = b;
        carpets[i].x2 = a + g;
        carpets[i].y2 = b + k;
    }

    int x, y;
    scanf("%d %d", &x, &y);

    int ans = -1;
    for (int i = n; i >= 1; i--) {
        if (x >= carpets[i].x1 && x <= carpets[i].x2 && y >= carpets[i].y1 && y <= carpets[i].y2) {
            ans = i;
            break;
        }
    }

    printf("%d", ans);

    return 0;
}