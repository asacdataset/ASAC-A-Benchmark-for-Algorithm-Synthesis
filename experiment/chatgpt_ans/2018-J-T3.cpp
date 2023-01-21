#include <bits/stdc++.h>
using namespace std;

int n, m;
int t[100005];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> t[i];
    sort(t + 1, t + n + 1);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int j = i + n / 2 - 1;
        if (j > n) j -= n;
        ans += 1ll * (t[j] + m - t[i]) % m;
    }
    cout << ans << endl;
    return 0;
}
