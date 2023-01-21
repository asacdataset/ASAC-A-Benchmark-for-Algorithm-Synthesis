#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100005

int n, ans, t[MAX_N], p[MAX_N], top;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (x == 0) { // subway
            ans += y;
            while (top > 0 && t[top] + 45 < z)
                top--;
            t[++top] = z;
            p[top] = y;
        } else { // bus
            while (top > 0 && t[top] + 45 < z)
                top--;
            if (top > 0 && p[top] >= y)
                ans += y;
            else
                ans += y;
        }
    }
    printf("%d\n", ans);
    return 0;
}
