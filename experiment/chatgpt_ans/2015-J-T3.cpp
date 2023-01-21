#include <stdio.h>

#define MOD 10007

int main() {
    int n, m, i, j, k;
    long long score = 0;
    scanf("%d%d", &n, &m);

    // Read in the numbers on the squares
    int numbers[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    // Read in the colors of the squares
    int colors[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &colors[i]);
    }

    // Iterate through all the squares on the tape
    for (i = 0; i < n; i++) {
        // Check if there are any other squares that satisfy the conditions of the special triplet
        for (j = i+1; j < n; j++) {
            if (colors[i] == colors[j]) {
                for (k = j+1; k < n; k++) {
                    if (colors[j] == colors[k] && j-i == k-j) {
                        // If a special triplet is found, add the score to the total
                        score += (i+k)*(numbers[i]+numbers[k]);
                        score %= MOD;
                    }
                }
            }
        }
    }

    printf("%lld\n", score);
    return 0;
}
