#include<iostream>
using namespace std;
const int N = 1005;
int n, ans;
int a[N];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, r = 1;
    while(r <= n) {
        while(r + 1 <= n && (a[r] < a[r + 1] || a[r] > a[r + 1])) r++;
        ans = max(ans, r - l + 1);
        l = r = r + 1;
    }
    cout << ans << endl;
    return 0;
}
