#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int g = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return g;
}

int main() {
    int a, b;
    cin >> a >> b;
    int x, y;
    int g = exgcd(a, b, x, y);
    if (g != 1) {
        cout << "No solution" << endl;
        return 0;
    }
    int x0 = (x % b + b) % b;
    cout << x0 << endl;
    return 0;
}