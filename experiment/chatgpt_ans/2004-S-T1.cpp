#include <stdio.h>

int main() {
    int money = 0, deposit = 0, budget, month;
    for (month = 1; month <= 12; month++) {
        scanf("%d", &budget);
        money += 300 - budget; // money left after receiving pocket money and spending
        if (money < 100) { // not enough money to deposit
            printf("-%d\n", month);
            return 0;
        }
        deposit += money / 100 * 100; // deposit in multiples of 100
        money %= 100; // keep the rest
    }
    printf("%d\n", deposit * 1.2 + money); // add 20% to deposit and add remaining money
    return 0;
}
