#include <stdio.h>
#include <vector>
#include <algorithm>

const int MAXN = 100005;

int n, m;

struct edge {
    int to, w;
};
std::vector<edge> G[MAXN];

int dep[MAXN], fa[MAXN][17];
int d[MAXN];

void dfs(int u, int f) {
    dep[u] = dep[f] + 1;
    fa[u][0] = f;
    for (int i = 1; i <= 16; i++) {
        fa[u][i] = fa[fa[u][i-1]][i-1];
    }
    for (auto e : G[u]) {
        if (e.to == f) continue;
        d[e.to] = d[u] + e.w;
        dfs(e.to, u);
    }
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) std::swap(u, v);
    for (int i = 16; i >= 0; i--) {
        if (dep[fa[u][i]] >= dep[v]) {
            u = fa[u][i];
