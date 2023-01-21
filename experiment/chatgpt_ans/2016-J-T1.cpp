#include <stdio.h>
#include <algorithm>

const int MAXN = 1e5 + 5;

int n;
int a[3], b[3];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 3; i++) {
        scanf("%d%d", &a[i], &b[i]);
    }
    int ans = 1e9;
    for (int i = 0; i <= MAXN; i++) {
        for (int j = 0; j <= MAXN; j++) {
            for (int k = 0; k <= MAXN; k++) {
                if (i * a[0] + j * a[1] + k * a[2] >= n) {
                    ans = std::min(ans, i * b[0] + j * b[1] + k * b[2]);
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}
