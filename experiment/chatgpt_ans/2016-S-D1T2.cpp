#include <stdio.h>
#include <string.h>

const int N = 100000 + 5;

int n, m, w[N], cnt[N], ans[N];
int head[N], tot, d[N], dis[N];
struct Edge {
    int next, to;
} e[N << 1];

void addEdge(int u, int v) {
    e[++tot].next = head[u];
    e[tot].to = v;
    head[u] = tot;
}

void dfs(int u, int fa) {
    d[u] = d[fa] + 1;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if (v != fa) {
            dfs(v, u);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        if (d[u] > d[v]) {
            swap(u, v);
        }
        dis[u]++;
        dis[v]--;
    }
    for (int i = 1; i <= n; i++) {
        dis[i] += dis[i - 1];
        cnt[d[i] + w[i]] += dis[i];
    }
    for (int i = 1; i <= n; i++) {
        ans[i] = cnt[i];
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}
