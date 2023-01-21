#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 200005;
int n, head[N], ver[N], nxt[N], tot, ans, match[N], vis[N];

void add(int x, int y) {
    ver[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

bool dfs(int x) {
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (!vis[y]) {
            vis[y] = 1;
            if (!match[y] || dfs(match[y])) {
                match[y] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(i, x);
        add(i, y);
    }
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        if (!dfs(i)) {
            printf("-1\n");
            return 0;
        }
        ans += vis[match[i]];
    }
    printf("%d\n", ans);
    return 0;
}
