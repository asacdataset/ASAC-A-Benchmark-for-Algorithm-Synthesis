#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}
int main(){
    int a, b, l;
    cin >> a >> b >> l;
    int g = gcd(a, b);
    a /= g, b /= g;
    while(a <= l && b <= l){
        if(gcd(a, b) == 1){
            cout << a << " " << b << endl;
            return 0;
        }
        a++; b++;
    }
    cout << -1 << endl;
    return 0;
}
