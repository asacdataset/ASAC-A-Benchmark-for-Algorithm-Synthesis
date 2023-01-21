#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int t[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }
    int round = 0;
    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        int j = i, cnt = 0;
        while (!visited[j]) {
            visited[j] = 1;
            j = t[j] - 1;
            cnt++;
        }
        if (cnt > 1) round = round > cnt ? round : cnt;
    }
    printf("%d", round);
    return 0;
}
