#include <stdio.h>
#include <string.h>

int n, k;

void grayCode(int n, int k) {
    if (n == 1) {
        printf("%d", k);
        return;
    }
    int m = 1 << (n - 1);
    if (k < m) {
        grayCode(n - 1, k);
    } else {
        printf("%d", k / m);
        grayCode(n - 1, k % m);
    }
}

int main() {
    scanf("%d%d", &n, &k);
    grayCode(n, k);
    return 0;
}
