#include <stdio.h>

int main() {
    int L, R;
    scanf("%d %d", &L, &R);
    int count = 0;
    for (int i = L; i <= R; i++) {
        int n = i;
        while (n > 0) {
            if (n % 10 == 2) {
                count++;
            }
            n /= 10;
        }
    }
    printf("%d", count);
    return 0;
}
