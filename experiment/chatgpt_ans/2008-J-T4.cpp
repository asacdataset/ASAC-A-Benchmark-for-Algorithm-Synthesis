#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int arr[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < arr[i][j]; k++) {
                if (k == 0) {
                    if (i == m - 1) {
                        printf("+");
                    } else {
                        if (arr[i][j] > arr[i + 1][j]) {
                            printf("+");
                        } else {
                            printf(".");
                        }
                    }
                } else {
                    if (i == m - 1) {
                        printf("|");
                    } else {
                        if (arr[i][j] > arr[i + 1][j]) {
                            printf("|");
                        } else {
                            printf(".");
                        }
                    }
                }
            }
            if (i == m - 1) {
                printf("-");
            } else {
                if (arr[i][j] > arr[i + 1][j]) {
                    printf("-");
                } else {
                    printf(".");
                }
            }
            if (j == n - 1) {
                printf("\n");
            } else {
                if (i == m - 1) {
                    printf("+");
                } else {
                    if (arr[i][j] > arr[i][j + 1]) {
                        printf("+");
                    } else {
                        printf(".");
                    }
                }
                if (i == m - 1) {
                    for (int k = 0; k < arr[i][j]; k++) {
                        printf("-");
                    }
                } else {
                    for (int k = 0; k < arr[i][j]; k++) {
                        if (k == 0) {
                            if (arr[i][j] > arr[i][j + 1]) {
                                printf("/");
                            } else {
                                printf(".");
                            }
                        } else {
                            if (arr[i][j] > arr[i][j + 1]) {
                                printf(".");
                            } else {
                                printf(".");
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
