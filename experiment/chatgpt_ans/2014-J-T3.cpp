#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, i, j, ans = 0;
    cin >> n >> i >> j;
    i--; j--;
    while(i >= 0 && j >= 0){
        ans += (i + j);
        i--; j--;
    }
    ans += (i + j + 2) * (i + j + 1) / 2;
    ans += i + 1;
    cout << ans << endl;
    return 0;
}
