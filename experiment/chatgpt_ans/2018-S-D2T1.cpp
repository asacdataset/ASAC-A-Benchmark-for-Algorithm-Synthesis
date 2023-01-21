#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

int n, m;
int e, head[MAX_N], next[MAX_N], to[MAX_N], visited[MAX_N];
int path[MAX_N], len;

void add_edge(int u, int v) {
    next[e] = head[u];
    to[e] = v;
    head[u] = e++;
}

void dfs(int u) {
    visited[u] = 1;
    path[len++] = u;
    for (int i = head[u]; ~i; i = next[i]) {
        int v = to[i];
        if (!visited[v]) {
            dfs(v);
            path[len++] = u;
        }
    }
}

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs(1);
    for (int i = 0; i < len; i++)
        printf("%d ", path[i]);
    return 0;
}
