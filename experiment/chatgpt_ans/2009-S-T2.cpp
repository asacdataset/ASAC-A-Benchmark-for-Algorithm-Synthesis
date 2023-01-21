#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main(void) {
    int n, a0, a1, b0, b1, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d%d%d%d", &a0, &a1, &b0, &b1);
        int x = gcd(a0, b0);
        if(a1 % x != 0 || b1 % x != 0) printf("0\n");
        else printf("%d\n", lcm(a0 / x, b0 / x));
    }
    return 0;
}
