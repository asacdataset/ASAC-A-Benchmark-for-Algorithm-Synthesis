#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

const int MAX_N = 100005;
const int MAX_M = 200005;
const int INF = 2147483647;

int n, m;
int h[MAX_N], e[MAX_M], ne[MAX_M], idx;
int dist[MAX_N];
bool st[MAX_N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool bfs(int s, int t) {
    std::queue<int> q;
    memset(dist, -1, sizeof dist);
    dist[t] = 0, q.push(t);
    while (!q.empty()) {
        int ver = q.front();
        q.pop();
        for (int i = h[ver]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] == -1) {
                dist[j] = dist[ver] + 1;
                q.push(j);
            }
        }
    }
    return dist[s] != -1;
}

int dfs(int u, int t, int limit) {
    if (u == t) return limit;
    int flow = 0;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (dist[j] == dist[u] - 1 && !st[j]) {
            int t = dfs(j, t, std::min(limit, e[i ^ 1]));
            if (!t) dist[j] = -1;
            flow += t, limit -= t;
            e[i] -= t, e[i ^ 1] += t;
            if (!limit) break;
        }
    }
    return flow;
}

int dinic(int s, int t) {
    int res = 0, flow;
    while (bfs(s, t)) {
        memcpy(h, ne, sizeof h);
        while (flow = dfs(s, t, INF)) res += flow;
    }
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    int s, t;
    scanf("%d%d", &s, &t);
    int res = dinic(s, t);
    if (res >= INF) res = -1;
    printf("%d\n", res);
    return 0;
}
