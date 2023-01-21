#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_N 100000

struct Edge {
    int u, v, w;
} edges[MAX_N];

int n, m;
int e, head[MAX_N], next[MAX_N], to[MAX_N], weight[MAX_N];
int dist[MAX_N], dp[MAX_N];
bool visited[MAX_N];

void add_edge(int u, int v, int w) {
    next[e] = head[u];
    to[e] = v;
    weight[e] = w;
    head[u] = e++;
}

int dfs(int u) {
    if (visited[u]) return dp[u];
    visited[u] = true;
    int v, w;
    for (int i = head[u]; ~i; i = next[i]) {
        v = to[i], w = weight[i];
        dp[u] = max(dp[u], dfs(v) + w);
    }
    return dp[u];
}

int main() {
    scanf("%d%d", &n, &m);
    int u, v, w;
    memset(head, -1, sizeof(head));
    for (int i = 1; i < n; i++) {
        scanf("%d%d%d", &u, &v, &w);
        edges[i].u = u, edges[i].v = v, edges[i].w = w;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        memset(dp, 0, sizeof(dp));
        ans = max(ans, dfs(i));
    }
    printf("%d", ans / 2);
    return 0;
}
