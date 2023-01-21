#include<stdio.h>
int main() {
    int n, m, i, j, k, s, level[1005], maxlevel, cnt;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) level[i] = 1; // initialize level of each station to 1
    for (i = 1; i <= m; i++) {
        scanf("%d", &s);
        maxlevel = level[s]; // find max level of the stopping stations
        for (j = 1; j <= s; j++) {
            scanf("%d", &k);
            maxlevel = maxlevel > level[k] ? maxlevel : level[k]; // update max level
        }
        for (j = 1; j <= s; j++) {
            scanf("%d", &k);
            level[k] = maxlevel; // set level of all stopping stations to max level
        }
    }
    cnt = 0; // count number of levels
    for (i = 1; i <= n; i++) if (level[i] > cnt) cnt = level[i];
    printf("%d", cnt);
    return 0;
}
