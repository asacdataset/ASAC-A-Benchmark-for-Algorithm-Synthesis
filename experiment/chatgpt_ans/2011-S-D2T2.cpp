#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1000005;
int n, m, s;
int w[MAXN], v[MAXN], l[MAXN], r[MAXN];
double ans = INF;

int main() {
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &w[i], &v[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &l[i], &r[i]);
    }

    for (int i = 1; i <= n; i++) {
        double W = 1.0 * w[i];
        double sum = 0;
        for (int j = 1; j <= m; j++) {
            double tmp = 0;
            for (int k = l[j]; k <= r[j]; k++) {
                tmp += v[k] * 1.0 / W;
            }
            sum += tmp;
        }
        ans = min(ans, abs(sum - s));
    }

    printf("%.0lf\n", ans);
    return 0;
}
