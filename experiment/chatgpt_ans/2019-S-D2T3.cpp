#include <iostream>
#include <vector>

using namespace std;

const int N = 100005;

vector<int> edges[N];
int size[N], n;
long long ans;

int dfs(int now, int father) {
    size[now] = 1;
    int sum = 0;
    for (int i = 0; i < edges[now].size(); i++) {
        int v = edges[now][i];
        if (v == father) continue;
        sum += dfs(v, now);
        size[now] += size[v];
    }
    int cnt = n - size[now];
    for (int i = 0; i < edges[now].size(); i++) {
        int v = edges[now][i];
        if (v == father) continue;
        ans += (long long)min(cnt, size[v]);
    }
    return size[now];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            edges[i].clear();
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        ans = 0;
        dfs(1, 0);
        cout << ans << endl;
    }
    return 0;
}
