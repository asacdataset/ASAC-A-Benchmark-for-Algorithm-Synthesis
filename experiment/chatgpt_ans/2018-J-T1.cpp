#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    getline(cin, s);
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ' && s[i] != '\n') ans++;
    }
    cout << ans << endl;
    return 0;
}
