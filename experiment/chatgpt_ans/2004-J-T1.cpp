#include <stdio.h>

int main() {
    int i, school, classes, unhappy, unhappy_day, unhappy_time;
    unhappy = 0;
    for (i = 1; i <= 7; i++) {
        scanf("%d %d", &school, &classes);
        int total_time = school + classes;
        if (total_time > 8) {
            if (total_time > unhappy_time) {
                unhappy = 1;
                unhappy_time = total_time;
                unhappy_day = i;
            }
        }
    }
    if (unhappy == 1) {
        printf("%d", unhappy_day);
    } else {
        printf("0");
    }
    return 0;
}