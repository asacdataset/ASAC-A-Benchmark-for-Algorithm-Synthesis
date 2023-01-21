#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INF 0x3f3f3f3f

int n, m, v, e;
int c[2005], d[2005];
double k[2005];
int dist[305][305];
double dp[2005][2005];

int main() {
    scanf("%d%d%d%d", &n, &m, &v, &e);

    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &d[i]);
    for (int i = 1; i <= n; i++) scanf("%lf", &k[i]);

    memset(dist, 0x3f, sizeof(dist));
    for (int i = 1; i <= v; i++) dist[i][i] = 0;

    for (int i = 0; i < e; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        dist[a][b] = dist[b][a] = w;
    }

    for (int k = 1; k <= v; k++)
        for (int i = 1; i <= v; i++)
            for (int j = 1; j <= v; j++)
                dist[i][j] = fmin(dist[i][j], dist[i][k] + dist[k][j]);

    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = INF;

    dp[0][1] = 0;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            dp[i][j] = fmin(dp[i][j], dp[i][j-1] + dist[c[j-1]][c[j]]);
            if (i >= 1) dp[i][j] = fmin(dp[i][j], dp[i-1][j-1] + dist[d[j-1]][c[j]] + k[j-1]);
        }

    printf("%.2lf", dp[m][n]);

    return 0;
}
