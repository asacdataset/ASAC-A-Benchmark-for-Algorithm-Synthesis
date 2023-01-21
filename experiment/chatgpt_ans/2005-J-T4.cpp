#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int previous = n % (int)pow(10, k); // find the last k digits of n^1
    for (int i = 2; i <= 100; i++) { // check up to n^100
        int current = (int)pow(n, i) % (int)pow(10, k);
        if (current == previous) {
            printf("%d", i - 1);
            return 0;
        }
        previous = current;
    }
    printf("-1");
    return 0;
}
