#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}

int main() {
    int n, i, ans = 0, a[30005];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp);
    for (i = 0; i < n - 1; i++) {
        a[i + 1] += a[i];
        ans += a[i];
    }
    printf("%d\n", ans);
    return 0;
}
