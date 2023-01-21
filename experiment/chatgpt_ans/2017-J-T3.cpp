#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

const int MAXN = 305;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m, color[MAXN][MAXN], dis[MAXN][MAXN];
bool vis[MAXN][MAXN];

struct Node {
    int x, y, step;
    Node(int x=0, int y=0, int step=0):x(x), y(y), step(step) {}
};

bool check(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > m) return false;
    if (vis[x][y]) return false;
    return true;
}

int bfs(int sx, int sy, int ex, int ey) {
    memset(vis, false, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    queue<Node> q;
    q.push(Node(sx, sy, 0));
    vis[sx][sy] = true;
    dis[sx][sy] = 0;

    while (!q.empty()) {
        Node now = q.front(); q.pop();
        int x = now.x, y = now.y, step = now.step;
        if (x == ex && y == ey) return step;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (!check(nx, ny)) continue;

            if (color[nx][ny] == color[x][y]) {
                vis[nx][ny] = true;
                q.push(Node(nx, ny, step));
                dis[nx][ny] = step;
            } else {
                if (color[nx][ny] != -1) {
                    vis[nx][ny] = true;
                    q.push(Node(nx, ny, step + 1));
                    dis[nx][ny] = step + 1;
                } else {
                    vis[nx][ny] = true;
                    q.push(Node(nx, ny, step + 2));
                    dis[nx][ny] = step + 2;
                }
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(color, -1, sizeof(color));
    for (int i = 1; i <= m; i++) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        color[x][y] = c;
    }

    printf("%d\n", bfs(1, 1, n, n));
    return 0;
}
