#include <stdio.h>

int main() {
    int n, m, a[100], count = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int x = 1; x <= m; x++) {
        int sum = 0;
        for (int i = 0; i <= n; i++) {
            sum += a[i] * pow(x, i);
        }
        if (sum == 0) {
            printf("%d ", x);
            count++;
        }
    }
    printf("\n%d\n", count);
    return 0;
}
