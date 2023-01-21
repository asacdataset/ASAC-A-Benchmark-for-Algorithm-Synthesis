#include <stdio.h>
#include <string.h>

#define MAX_N 1005

int n, m, q, head[MAX_N], to[MAX_N << 1], nxt[MAX_N << 1], tot;
int dep[MAX_N];
bool vis[MAX_N];

void addEdge(int u, int v) {
    to[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}

void dfs(int u, int d) {
    dep[u] = d;
    vis[u] = true;
    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        if (!vis[v])
            dfs(v, d + 1);
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    dfs(1, 1);
    for (int i = 1; i <= q; i++) {
        int a, l;
        scanf("%d%d", &a, &l);
        if (dep[a] < l)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
