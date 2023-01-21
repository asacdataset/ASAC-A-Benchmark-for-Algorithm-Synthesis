#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int magic_square[n][n];
    int i = n / 2, j = n - 1;
    for (int num = 1; num <= n * n; ) {
        if (i == -1 && j == n) {
            j = n - 2;
            i = 0;
        } else {
            if (j == n) {
                j = 0;
            }
            if (i < 0) {
                i = n - 1;
            }
        }
        if (magic_square[i][j]) {
            j -= 2;
            i++;
            continue;
        } else {
            magic_square[i][j] = num++;
        }
        j++; i--;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", magic_square[i][j]);
        }
        printf("\n");
    }
    return 0;
}
