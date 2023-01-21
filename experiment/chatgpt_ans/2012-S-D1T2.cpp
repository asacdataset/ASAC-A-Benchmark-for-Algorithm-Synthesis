#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110;

int n;
struct Person {
    int a, b;
    double coins;
}p[N];

bool cmp(Person x, Person y) {
    return x.coins > y.coins;
}

int main() {
    cin >> n;
    cin >> p[0].a >> p[0].b;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].a >> p[i].b;
        p[i].coins = (double)p[i].a / p[i].b;
    }
    sort(p + 1, p + n + 1, cmp);
    double coins = p[0].a;
    for (int i = 1; i <= n; i++) {
        coins = (coins * p[i].a) / p[i].b;
        p[i].coins = coins;
    }
    int maxCoins = 0;
    for (int i = 0; i <= n; i++) {
        maxCoins = max(maxCoins, (int)p[i].coins);
    }
    cout << maxCoins << endl;
    return 0;
}w