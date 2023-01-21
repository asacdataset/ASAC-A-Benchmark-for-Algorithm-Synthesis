#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j, max, total = 0;
    char name[20], leader, western;
    int avg, eva, papers, maxName;
    int sum[1000] = {0}; // sum[i] stores the total scholarship for student i

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s %d %d %c %c %d", name, &avg, &eva, &leader, &western, &papers);
        if (avg > 80 && papers > 0) {
            sum[i] += 8000; // Academician Scholarship
        }
        if (avg > 85 && eva > 80) {
            sum[i] += 4000; // May 4th Scholarship
        }
        if (avg > 90) {
            sum[i] += 2000; // Outstanding Academic Results Scholarship
        }
        if (western == 'Y' && avg > 85) {
            sum[i] += 1000; // Western Scholarship
        }
        if (leader == 'Y' && eva > 80) {
            sum[i] += 850; // Class Contribution Scholarship
        }
    }

    max = sum[0];
    maxName = 0;
    for (i = 1; i < n; i++) {
        if (sum[i] > max) {
            max = sum[i];
            maxName = i;
        }
    }
    printf("%s\n%d\n", name, max);

    for (i = 0; i < n; i++) {
        total += sum[i];
    }
    printf("%d", total);

    return 0;
}
