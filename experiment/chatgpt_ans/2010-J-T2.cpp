#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int w[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    int time = 0;
    int faucets = m;
    for (int i = 0; i < n; i++) {
        if (faucets > 0) {
            time += w[i];
            faucets--;
        } else {
            time += w[i];
        }
    }
    printf("%d", time);
    return 0;
}
