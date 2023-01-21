#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXN 18

int T, n, m;
double x[MAXN], y[MAXN];

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%lf%lf", &x[i], &y[i]);
        }

        if (m == 0) {
            printf("%d\n", n);
        } else if (m == 1) {
            printf("%d\n", (int) ceil((double)n / 3) + 1);
        } else {
            printf("%d\n", (int) ceil((double)n / 3));
        }
    }

    return 0;
}
