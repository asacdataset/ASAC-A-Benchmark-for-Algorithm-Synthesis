#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n + 1];
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }

    if (a[n] > 0) {
        cout << a[n] << "x^" << n;
    }
    else if (a[n] < 0) {
        cout << a[n] << "x^" << n;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > 0) {
            cout << " + " << a[i];
        }
        else if (a[i] < 0) {
            cout << " - " << abs(a[i]);
        }
        if (i > 1) {
            cout << "x^" << i;
        }
        else if (i == 1) {
            cout << "x";
        }
    }
    return 0;
}
