#include <iostream>
#include <string>
using namespace std;

string expr;

int main() {
    cin >> expr;
    long long res = 1;
    long long sum = 0;
    for (int i = 0; i < expr.size(); i++) {
        if (expr[i] == '*') {
            int j = i + 1;
            long long tmp = 0;
            while (j < expr.size() && isdigit(expr[j])) {
                tmp = tmp * 10 + expr[j] - '0';
                j++;
            }
            i = j - 1;
            res = (res * tmp) % 10000;
        } else {
            int j = i;
            long long tmp = 0;
            while (j < expr.size() && isdigit(expr[j])) {
                tmp = tmp * 10 + expr[j] - '0';
                j++;
            }
            i = j - 1;
            sum += tmp;
        }
    }
    cout << (res * (sum % 10000)) % 10000 << endl;
    return 0;
}