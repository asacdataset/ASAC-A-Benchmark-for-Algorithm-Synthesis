#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

int T;
int n, m, k, p;
int dis[MAXN], vis[MAXN], cnt[MAXN];

vector<pair<int, int> > g[MAXN];

void dijkstra(int s) {
    priority_queue<pair<int, int> > q;
    for (int i = 1; i <= n; i++) dis[i] = 1e9;
    memset(vis, false, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    dis[s] = 0;
    q.push({0, s});
    while (!q.empty()) {
        int x = q.top().second;
        q.pop();
        if (vis[x]) continue;
        vis[x] = true;
        for (int i = 0; i < g[x].size(); i++) {
            int y = g[x][i].first, z = g[x][i].second;
            if (dis[y] > dis[x] + z) {
                dis[y] = dis[x] + z;
                cnt[y] = cnt[x];
                q.push({-dis[y], y});
            } else if (dis[y] == dis[x] + z) {
                cnt[y] = (cnt[y] + cnt[x]) % p;
            }
        }
    }
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d", &n, &m, &k, &p);
        for (int i = 1; i <= n; i++) g[i].clear();
        while (m--) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            g[a].push_back({b, c});
        }
        dijkstra(1);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dis[i] <= dis[n] + k) ans = (ans + cnt[i]) % p;
        }
        if (ans == 0) printf("-1\n");
        else printf("%d\n", ans);
    }
    return 0;
}
