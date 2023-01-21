#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);

    int prime = 0;
    int sqrt_n = (int) sqrt(n);
    for (int i = 2; i <= sqrt_n; i++) {
        if (n % i == 0) {
            prime = i;
            break;
        }
    }

    if (prime == 0) {
        printf("%d", n);
    } else {
        int other_prime = n / prime;
        if (other_prime == prime) {
            printf("%d", prime);
        } else {
            printf("%d", other_prime);
        }
    }

    return 0;
}