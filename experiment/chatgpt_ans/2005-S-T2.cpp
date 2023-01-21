#include <stdio.h>
#include <string.h>

int L, S, T, M, pebbles[10000];
int dp[10000], INF = 0x3f3f3f3f;

int main() {
    int i, j, k, cur;
    scanf("%d", &L);
    scanf("%d %d %d", &S, &T, &M);
    for (i = 1; i <= M; i++) {
        scanf("%d", &pebbles[i]);
    }
    pebbles[0] = 0;
    pebbles[M+1] = L;

    for (i = 0; i <= M+1; i++) {
        dp[i] = INF;
    }
    dp[0] = 0;

    for (i = 0; i <= M; i++) {
        for (j = S; j <= T; j++) {
            if (i + j <= M + 1) {
                cur = pebbles[i+j] - pebbles[i];
                dp[i+j] = min(dp[i+j], dp[i] + (cur < j));
            }
        }
    }

    printf("%d", dp[M+1]);
    return 0;
}
