#include<iostream>
using namespace std;
int n, ans, h[1000005];
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i];
    for(int i = 2; i <= n; i++) {
        if(h[i] > h[i-1]) ans += h[i] - h[i-1];
    }
    cout << ans << endl;
    return 0;
}
