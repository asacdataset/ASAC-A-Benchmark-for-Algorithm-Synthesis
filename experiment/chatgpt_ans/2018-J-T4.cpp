#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
int n;
int v[N], l[N], r[N];

int dfs(int x) {
    if (x == -1) return 0;
    int left = dfs(l[x]), right = dfs(r[x]);
    if (left == -1 || right == -1) return -1;
    if (left != right) return -1;
    if (v[l[x]] != v[r[x]]) return -1;
    return 1 + left + right;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dfs(i));
    cout << ans << endl;
    return 0;
}
