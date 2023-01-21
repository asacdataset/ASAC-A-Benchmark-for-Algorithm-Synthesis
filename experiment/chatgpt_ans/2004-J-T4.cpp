#include <stdio.h>

int main() {
    int n, m, i, j, a[10001], b[10001], min, min_index;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++) {
        min = 10001;
        min_index = -1;
        for (j = 0; j < n; j++) {
            if (a[j] > i + m && a[j] < min) {
                min = a[j];
                min_index = j;
            }
        }
        if (min_index != -1) {
            b[i] = min;
            a[min_index] = 10001;
        }
    }
    for (i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    return 0;
}
