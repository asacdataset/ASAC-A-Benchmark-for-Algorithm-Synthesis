#include <stdio.h>
#include <string.h>

int k, n;
int f[20][20005];

int main() {
    scanf("%d%d", &k, &n);
    f[0][0] = 1;
    for (int i = 1; i <= 15; i++) {
        for (int j = 0; j <= i * (1 << (i - 1)); j++) {
            f[i][j] = f[i - 1][j] * k + f[i - 1][j ^ (1 << (i - 1))];
        }
    }
    printf("%d\n", f[15][n - 1]);
    return 0;
}
