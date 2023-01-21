#include <stdio.h>
#include <string.h>

const int N = 100000 + 5;

int n, m;
int a[N], dir[N];
char s[N][15];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d%s", &dir[i], s[i]);
    }
    int cur = 1;
    for (int i = 1; i <= m; i++) {
        int op, x;
        scanf("%d%d", &op, &x);
        if (!dir[cur]) {
            op ^= 1;
        }
        if (!op) {
            cur = (cur - x + n - 1) % n + 1;
        } else {
            cur = (cur + x) % n + 1;
        }
    }
    printf("%s\n", s[cur]);
    return 0;
}
