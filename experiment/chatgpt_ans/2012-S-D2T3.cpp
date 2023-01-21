#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 10000

struct Edge {
    int u, v, w;
};

int n, m;
int army[MAX_N];
int leaf[MAX_N];
bool visited[MAX_N];
struct Edge edges[MAX_N - 1];

void dfs(int u, int parent) {
    if (visited[u]) return;
    visited[u] = true;
    if (army[u]) {
        leaf[u] = 1;
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        int v = edges[i].u == u ? edges[i].v : edges[i].u;
        if (v == parent) continue;
        dfs(v, u);
        leaf[u] += leaf[v];
    }
}

int dfs2(int u, int parent) {
    if (visited[u]) return 0;
    visited[u] = true;
    if (leaf[u]) return 0;
    int res = 0x3f3f3f3f;
    for (int i = 0; i < n - 1; i++) {
        int v = edges[i].u == u ? edges[i].v : edges[i].u;
        if (v == parent) continue;
        res = leaf[u] == leaf[v] ?
            min(res, dfs2(v, u) + edges[i].w) :
            min(res, dfs2(v, u));
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int city;
        scanf("%d", &city);
        army[city] = true;
    }
    dfs(1, -1);
    memset(visited, 0, sizeof(visited));
    int res = dfs2(1, -1);
    if (res == 0x3f3f3f3f) {
        printf("-1\n");
    } else {
        printf("%d\n", res);
    }
    return 0;
}
