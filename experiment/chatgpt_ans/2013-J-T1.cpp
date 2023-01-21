#include <iostream>
using namespace std;

int n, x, ans;

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        int t = i;
        while (t > 0) {
            if (t % 10 == x) ans++;
            t /= 10;
        }
    }
    cout << ans << endl;
    return 0;
}
