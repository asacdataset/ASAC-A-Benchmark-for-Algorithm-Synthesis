#include <stdio.h>

int main() {
    int t, n;
    scanf("%d%d", &t, &n);
    while (t--) {
        int cards[14][5] = {0};
        int min_draws = 0;
        for (int i = 0; i < n; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            if (a == 0) {
                cards[13][b]++;
                min_draws++;
            } else {
                cards[a-1][b]++;
                if (cards[a-1][b] == 4) {
                    cards[a-1][b] = 0;
                    min_draws++;
                }
            }
        }
        for (int i = 0; i < 13; i++) {
            min_draws += cards[i][1] + cards[i][2] + cards[i][3] + cards[i][4];
        }
        printf("%d\n", min_draws);
    }
    return 0;
}
