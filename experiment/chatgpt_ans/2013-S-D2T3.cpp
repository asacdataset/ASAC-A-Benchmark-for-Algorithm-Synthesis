#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 105;

int n, m, q, sx, sy, ex, ey, tx, ty, dist[MAXN][MAXN];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
char a[MAXN][MAXN];

struct Node {
    int x, y;
    Node(int x, int y) : x(x), y(y) {}
};

int bfs() {
    memset(dist, -1, sizeof(dist));
    queue<Node> Q;
    Q.push(Node(sx, sy));
    dist[sx][sy] = 0;
    while (!Q.empty()) {
        Node now = Q.front();
        Q.pop();
        if (now.x == tx && now.y == ty) {
            return dist[now.x][now.y];
        }
        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i], ny = now.y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m) {
                continue;
            }
            if (a[nx][ny] == '1' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[now.x][now.y] + 1;
                Q.push(Node(nx, ny));
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%s", a[i] + 1);
    }
    while (q--) {
        scanf("%d%d%d%d%d%d", &ex, &ey, &sx, &sy, &tx, &ty);
        swap(a[ex][ey], a[sx][sy]);
        printf("%d\n", bfs());
        swap(a[ex][ey], a[sx][sy]);
    }
    return 0;
}
