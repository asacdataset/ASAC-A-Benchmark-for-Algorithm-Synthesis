#include <stdio.h>
#include <vector>

const int MAXN = 100005;

int T;
int n;
int a[MAXN];
std::vector<int> g[MAXN];
int p[MAXN];
int d[MAXN], vis[MAXN], ans[MAXN];

void dfs(int u, int fa, int c) {
    p[a[u]] = c;
    for (int v : g[u]) {
        if (v == fa) continue;
        dfs(v, u, c + 1);
    }
}

void dfs2(int u) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (vis[v]) continue;
        dfs2(v);
        d[u] += d[v];
    }
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            g[i].clear();
            d[i] = 1;
            vis[i] = 0;
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1, 0, 1);
        dfs2(1);
        int pos = 1;
        for (int i = 1; i <= n; i++) {
            while (d[a[pos]] == 0) pos++;
            ans[i] = a[pos];
            d[a[pos]] = 0;
        }
        for (int i = 1; i <= n; i++)
            printf("%d%c", ans[i], " \n"[i == n]);
    }
    return 0;
}
