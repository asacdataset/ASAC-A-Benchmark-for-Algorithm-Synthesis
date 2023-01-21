#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
int n, ans;
int d[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int l = 1, r = 1; r <= n; r++) {
        while (l <= r && d[l] == 0) l++;
        if (l > r) continue;
        int cnt = 0;
        for (int i = l; i <= r; i++) {
            if (d[i] == 0) {
                ans += cnt;
                cnt = 0;
                l = i + 1;
            } else {
                cnt += d[i];
            }
        }
        ans += cnt;
    }
    cout << ans << endl;
    return 0;
}
