#include <stdio.h>

int n, m, alt[101][101], storages, arid;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &alt[i][j]);
        }
    }

    for (int j = 1; j <= m; j++) {
        if (alt[1][j] <= alt[1][j-1]) {
            storages++;
        }
        for (int i = 2; i <= n; i++) {
            if (alt[i][j] <= alt[i-1][j] || alt[i][j] <= alt[i][j-1]) {
                storages++;
                break;
            }
        }
    }

    for (int j = 1; j <= m; j++) {
        if (alt[n][j] > alt[n][j-1] && alt[n][j] > alt[n-1][j]) {
            arid++;
        }
    }

    if (arid == 0) {
        printf("1 %d\n", storages);
    } else {
        printf("0 %d\n", arid);
    }

    return 0;
}
