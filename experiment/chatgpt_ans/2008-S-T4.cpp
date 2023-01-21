#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
stack<int> s1, s2;
int a[100005], n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int l = 1, r = n;
    for (int i = 1; i <= n; i++) {
        if (a[i] == l) {
            s1.push(a[i]);
            l++;
        }
        else if (a[i] == r) {
            s2.push(a[i]);
            r--;
        }
        else {
            break;
        }
    }
    if (s1.size() + s2.size() != n) {
        printf("0");
        return 0;
    }
    while (s1.size()) {
        printf("b ");
        s1.pop();
    }
    while (s2.size()) {
        printf("d ");
        s2.pop();
    }
    return 0;
}
