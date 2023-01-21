#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int count[150000001] = {0}; // Initialize an array to keep count of each number
    for (i = 0; i < n; i++) {
        count[a[i]]++;
    }
    for (i = 1; i <= 150000000; i++) {
        if (count[i] != 0) {
            printf("%d %d\n", i, count[i]);
        }
    }
    return 0;
}
