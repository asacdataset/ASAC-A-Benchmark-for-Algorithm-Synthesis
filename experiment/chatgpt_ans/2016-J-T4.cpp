#include <stdio.h>

const int N = 15000 + 5;
const int M = 40000 + 5;

int n, m, a[M], cnt[M][4];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            if (a[i] < a[j]) {
                int d = a[j] - a[i];
                if (d % 2 == 0) {
                    int c = a[j] - d / 2;
                    if (c > a[i]) {
                        cnt[i][0]++;
                        cnt[j][1]++;
                        cnt[c][2]++;
                        cnt[a[j]][3]++;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        printf("%d %d %d %d\n", cnt[a[i]][0], cnt[a[i]][1], cnt[a[i]][2], cnt[a[i]][3]);
    }
    return 0;
}
