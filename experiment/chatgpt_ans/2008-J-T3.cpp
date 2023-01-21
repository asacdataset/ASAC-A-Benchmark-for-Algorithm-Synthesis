#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int ans = 1;
    for (int i = 0; i < m; i++) {
        ans = ans * (n - 1);
    }
    printf("%d", ans);
    return 0;
}
