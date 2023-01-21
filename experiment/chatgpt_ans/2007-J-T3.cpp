#include <stdio.h>

int main() {
    int m, s, t;
    scanf("%d %d %d", &m, &s, &t);

    int time = 0;
    int distance = 0;
    int mana = m;
    while (time < t) {
        if (distance + 17 >= s) {
            printf("Yes\n%d", time);
            return 0;
        }
        if (mana >= 10) {
            distance += 60;
            mana -= 10;
            time++;
        } else {
            mana += 4;
            time++;
        }
    }
    printf("No\n%d", distance + 17 * (t - time));
    return 0;
}
