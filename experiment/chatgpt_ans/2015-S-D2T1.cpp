#include <stdio.h>

int main() {
    int l, n, m;
    scanf("%d%d%d", &l, &n, &m);
    int d[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
    }
    int max_min_jump = 0;
    for (int i = 0; i <= n - m; i++) {
        int min_jump = l - d[i + m - 1];
        max_min_jump = min_jump > max_min_jump ? min_jump : max_min_jump;
    }
    printf("%d", max_min_jump);
    return 0;
}
