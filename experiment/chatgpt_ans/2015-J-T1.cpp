#include <stdio.h>

int main() {
    int k, coins = 0, days = 1, coinsPerDay = 1;
    scanf("%d", &k);
    while (days <= k) {
        coins += coinsPerDay * days;
        days += coinsPerDay;
        coinsPerDay++;
    }
    printf("%d", coins);
    return 0;
}
