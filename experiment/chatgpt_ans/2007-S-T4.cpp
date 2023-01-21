#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define MAX_M 200005

int n, s;
int head[MAX_N], nxt[MAX_M], to[MAX_M], w[MAX_M], cnt;
int f[MAX_N], g[MAX_N], ans;

void add_edge(int u, int v, int weight) {
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
    w[cnt] = weight;
}

void dfs(int u, int fa) {
    int v;
    for (int i = head[u]; i; i = nxt[i]) {
        v = to[i];
        if (v == fa) continue;
        dfs(v, u);
        if (g[v] + w[i] > g[u]) {
            f[u] = g[u];
            g[u] = g[v] + w[i];
        } else if (g[v] + w[i] > f[u]) {
            f[u] = g[v] + w[i];
        }
    }
}

void dfs2(int u, int fa) {
    int v;
    for (int i = head[u]; i; i = nxt[i]) {
        v = to[i];
        if (v == fa) continue;
        if (g[u] == g[v] + w[i]) {
            g[v] = f[v];
        } else {
            g[v] = g[u];
        }
        dfs2(v, u);
    }
}

int main() {
    scanf("%d %d", &n, &s);

    int u, v, weight;
    for (int i = 1; i < n; i++) {
        scanf("%d %d %d", &u, &v, &weight);
        add_edge(u, v, weight);
        add_edge(v, u, weight);
    }

    dfs(1, 0);
    dfs2(1, 0);

    for (int i = 1; i <= n; i++) {
        ans = max(ans, g[i]);
    }

    printf("%d\n", ans > s ? ans - s : 0);

    return 0;
}
