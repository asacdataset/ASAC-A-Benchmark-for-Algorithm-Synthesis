#include <stdio.h>
#include <stdlib.h>

struct player {
    int serial_number;
    int initial_score;
    int strength;
    int total_score;
};

int compare(const void *a, const void *b) {
    struct player *p1 = (struct player *)a;
    struct player *p2 = (struct player *)b;
    if (p1->total_score != p2->total_score) {
        return p2->total_score - p1->total_score;
    } else {
        return p1->serial_number - p2->serial_number;
    }
}

int main() {
    int n, r, q;
    scanf("%d %d %d", &n, &r, &q);

    struct player players[2 * n];
    for (int i = 0; i < 2 * n; i++) {
        scanf("%d", &players[i].initial_score);
        players[i].serial_number = i + 1;
        players[i].total_score = players[i].initial_score;
    }
    for (int i = 0; i < 2 * n; i++) {
        scanf("%d", &players[i].strength);
    }

    // Your code here

    printf("%d", players[q - 1].serial_number);

    return 0;
}