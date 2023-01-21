#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5, M = 2e5 + 5;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
int dist[N], q[N], hh, tt;
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

bool spfa() {
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    hh = 0, tt = -1;
    dist[1] = 0;
    q[++tt] = 1;
    st[1] = true;
    while (hh <= tt) {
        int t = q[hh++];
        st[t] = false;
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                if (!st[j]) {
                    st[j] = true;
                    q[++tt] = j;
                }
            }
        }
    }
    return dist[n] < 1e9;
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    if (spfa()) printf("%d\n", dist[n]);
    else puts("0");
    return 0;
}
