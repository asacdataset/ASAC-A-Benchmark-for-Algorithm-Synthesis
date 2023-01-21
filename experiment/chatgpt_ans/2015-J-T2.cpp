#include <stdio.h>

int n, m;
char minefield[105][105];

int count_mines(int i, int j) {
    int count = 0;
    for (int ii = i-1; ii <= i+1; ii++) {
        for (int jj = j-1; jj <= j+1; jj++) {
            if (ii >= 0 && ii < n && jj >= 0 && jj < m) {
                if (minefield[ii][jj] == '*') {
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", minefield[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (minefield[i][j] == '*') {
                printf("*");
            } else {
                int mines = count_mines(i, j);
                printf("%d", mines);
            }
        }
        printf("\n");
    }
    return 0;
}
