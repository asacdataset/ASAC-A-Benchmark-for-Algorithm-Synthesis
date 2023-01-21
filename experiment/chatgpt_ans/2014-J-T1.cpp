#include<bits/stdc++.h>
using namespace std;
int n, a[105], ans;
bool flag[10005];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i != j)
                flag[a[i] + a[j]] = 1;
    for(int i = 1; i <= n; i++)
        if(flag[a[i]]) ans++;
    cout << ans << endl;
    return 0;
}
