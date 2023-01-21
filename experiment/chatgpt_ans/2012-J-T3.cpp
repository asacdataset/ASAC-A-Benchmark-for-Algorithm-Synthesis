#include <iostream>
using namespace std;

const int mod = 1000007;

int n, m;
int a[105];
int f[105][105];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= m; i++) f[0][i] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k <= min(j, a[i]); k++) {
                f[i][j] = (f[i][j] + f[i - 1][j - k]) % mod;
            }
        }
    }
    cout << f[n][m] << endl;
    return 0;
}