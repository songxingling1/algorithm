#include <bits/stdc++.h>
using namespace std;
char s[205][205];
int vis[205][205];
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int n, m;
int ex, ey;
struct block {
    int x, y, step;
    block(int a, int b, int c)
    : x(a)
    , y(b)
    , step(c) {}
    block()
    : x(0)
    , y(0)
    , step(0) {}
};
int bfs(int x, int y) {
    queue<block> que;
    que.push({x, y, 0});
    vis[x][y] = 1;
    block t;
    while (!que.empty()) {
        t = que.front();
        que.pop();
        if (t.x == ex && t.y == ey) {
            return t.step;
        }
        for (int i = 0; i < 4; i++) {
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];
            if (nx <= 0 || ny <= 0 || nx > n || ny > m)
                continue;
            if (s[nx][ny] != '#' && !vis[nx][ny]) {
                que.push({nx, ny, t.step + 1});
                vis[nx][ny] = 1;
            }
        }
    }
    return -1;
}
int main() {
    int t, sx, sy, ans;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> s[i][j];
                if (s[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                if (s[i][j] == 'E') {
                    ex = i;
                    ey = j;
                }
            }
        }
        memset(vis, 0, sizeof(vis));
        ans = bfs(sx, sy);
        if (ans == -1) {
            cout << "oop!" << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}