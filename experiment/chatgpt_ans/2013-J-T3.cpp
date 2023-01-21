#include <iostream>
#include <algorithm>
using namespace std;

int n, p;
int a[100005], f[100005], g[100005], ans;

int main() {
    cin >> n >> p;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        f[i] = max(f[i - 1] + a[i], a[i]);
        g[i] = max(g[i - 1], f[i]);
    }
    ans = g[n];
    for (int i = 1; i <= n; i++) {
        ans = max(ans, g[i - 1] + f[i]);
    }
    cout << (ans % p + p) % p << endl;
    return 0;
}
