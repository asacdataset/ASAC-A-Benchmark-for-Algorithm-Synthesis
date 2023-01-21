#include <bits/stdc++.h>
using namespace std;

int n, m, p1, s1, s2;
int c[100005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    cin >> m >> p1 >> s1 >> s2;
    long long power1 = 0, power2 = 0;
    for (int i = 1; i < m; i++) power1 += 1ll * (m - i) * c[i];
    for (int i = m + 1; i <= n; i++) power2 += 1ll * (i - m) * c[i];
    power1 += s1;
    power2 += s2;
    int ans = -1;
    long long diff = abs(power1 - power2);
    for (int i = 1; i <= n; i++) {
        if (i == p1) continue;
        long long p1_ = power1, p2_ = power2;
        if (i < m) p1_ += (m - i) * s2;
        else if (i > m) p2_ += (i - m) * s2;
        if (abs(p1_ - p2_) < diff) {
            diff = abs(p1_ - p2_);
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}
