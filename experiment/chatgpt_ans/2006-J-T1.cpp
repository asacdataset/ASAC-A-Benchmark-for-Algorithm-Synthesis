#include <stdio.h>
#include <stdlib.h>

int a[100005], b[100005];

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n, m = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp);
    for (int i = 0; i < n; i++) {
        if (i == 0 || a[i] != a[i - 1]) {
            b[m++] = a[i];
        }
    }
    printf("%d\n", m);
    for (int i = 0; i < m; i++) {
        printf("%d ", b[i]);
    }
    return 0;
}
