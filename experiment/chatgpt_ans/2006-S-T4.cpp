#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 205;
int k, w;
ll dp[MAXN][10];

int main() {
    scanf("%d %d", &k, &w);
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= k; i++) {
        dp[i][1] = 1;
    }
    for (int i = k + 1; i <= w; i++) {
        for (int j = 1; j <= min(i, 9); j++) {
            for (int l = 1; l < j; l++) {
                dp[i][j] += dp[i - 1][l];
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= min(w, 9); i++) {
        ans += dp[w][i];
    }
    printf("%lld\n", ans);
    return 0;
}
