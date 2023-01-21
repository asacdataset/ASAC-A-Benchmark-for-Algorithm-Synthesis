#include<stdio.h>
int main() {
    int n, m, k, x, ans;
    scanf("%d%d%d%d", &n, &m, &k, &x);
    ans = (x + k * m) % n; // calculate the final position of player x
    printf("%d", ans);
    return 0;
}
