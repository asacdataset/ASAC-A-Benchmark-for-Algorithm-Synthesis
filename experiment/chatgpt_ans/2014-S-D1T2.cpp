#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005
#define MOD 10007

int n, ans1, ans2;
int head[MAXN], to[MAXN << 1], next[MAXN << 1], cnt;
int w[MAXN], f[MAXN][3], g[MAXN];

inline void add(int u, int v) {
    next[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
}

void dfs1(int u, int fa) {
    f[u][0] = 1;
    for (int i = head[u]; i; i = next[i]) {
        int v = to[i];
        if (v == fa) continue;
        dfs1(v, u);
        f[u][0] += f[v][1];
        f[u][1] += f[v][2];
        f[u][2] += f[v][0];
    }
    ans1 = (ans1 + 1ll * f[u][1] * w[u]) % MOD;
}

void dfs2(int u, int fa) {
    for (int i = head[u]; i; i = next[i]) {
        int v = to[i];
        if (v == fa) continue;
        g[v] = (g[u] + 1ll * (n - f[v][0] - f[v][1]) * w[u]) % MOD;
        dfs2(v, u);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    dfs1(1, 0);
    g[1] = ans1;
    dfs2(1, 0);
    ans2 = 0;
    for (int i = 1; i <= n; i++) {
        ans2 = (ans2 + g[i]) % MOD;
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}
