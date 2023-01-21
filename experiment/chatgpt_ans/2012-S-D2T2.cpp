#include <iostream>
using namespace std;

const int N = 100010;

int n, m;
int r[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> r[i];
    for (int i = 1; i <= m; i++) {
        int dj, sj, tj;
        cin >> dj >> sj >> tj;
        for (int j = sj; j <= tj; j++) {
            r[j] -= dj;
            if (r[j] < 0) {
                cout << -1 << endl;
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << 0 << endl;
    return 0;
}