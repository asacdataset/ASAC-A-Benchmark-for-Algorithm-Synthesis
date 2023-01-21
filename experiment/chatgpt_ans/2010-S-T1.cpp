#include <stdio.h>
#include <string.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int words[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &words[i]);
    }
    int memory[m];
    int count = 0;
    int index = 0;
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < m; j++) {
            if (memory[j] == words[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            count++;
            memory[index] = words[i];
            index = (index + 1) % m;
        }
    }
    printf("%d", count);
    return 0;
}
