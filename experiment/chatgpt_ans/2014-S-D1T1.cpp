#include <stdio.h>

int n, na, nb;
int a[100005], b[100005];
int win[5][5] = {
    {0, 0, 1, 1, 0},
    {1, 0, 0, 0, 1},
    {0, 1, 0, 1, 0},
    {0, 1, 0, 0, 1},
    {1, 0, 1, 0, 0}
};

int main() {
    scanf("%d%d%d", &n, &na, &nb);
    for (int i = 0; i < na; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < nb; i++) {
        scanf("%d", &b[i]);
    }
    int sa = 0, sb = 0;
    for (int i = 0; i < n; i++) {
        sa += win[a[i % na]][b[i % nb]];
        sb += win[b[i % nb]][a[i % na]];
    }
    printf("%d %d\n", sa, sb);
    return 0;
}
