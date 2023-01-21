#include <stdio.h>
#include <string.h>

#define MAXN 100005

int n;
char s[MAXN];
int f[MAXN], d[MAXN], son[MAXN], dp[MAXN];

int main() {
    scanf("%d", &n);
    scanf("%s", s+1);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &f[i]);
        son[f[i]]++;
    }
    for (int i = 1; i <= n; i++)
        if (!son[i]) d[i] = 1;
    for (int i = n; i >= 1; i--)
        if (!d[i]) {
            for (int j = i; j; j = f[j])
                d[f[j]] += d[j];
        }
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[f[i]];
        if (s[i] == '(') dp[i]++;
        else dp[i]--;
        if (dp[i] < 0) dp[i] = 0;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (dp[i] == 0) ans ^= i * d[i];
    printf("%d\n", ans);
    return 0;
}
