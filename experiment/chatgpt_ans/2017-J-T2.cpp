#include <stdio.h>
#include <string.h>

int main() {
    int n, q, i;
    scanf("%d%d", &n, &q);

    int books[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &books[i]);
    }

    int l, r;
    for (i = 0; i < q; i++) {
        scanf("%d%d", &l, &r);
        int min = -1, j;
        for (j = 0; j < n; j++) {
            if (books[j] % (int) pow(10, l) == r) {
                if (min == -1 || books[j] < min) {
                    min = books[j];
                }
            }
        }
        printf("%d\n", min);
    }
    return 0;
}
