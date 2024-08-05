#include <bits/stdc++.h>
using namespace std;
char s[505][505];
int vis[505][505];
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int n, m;
struct ice {
    int x, y, step;
    ice(int a, int b, int c)
    : x(a)
    , y(b)
    , step(c) {}
    ice()
    : x(0)
    , y(0)
    , step(0) {}
};
int bfs(int x, int y) {
    queue<ice> que;
    que.push({x, y, 0});
    vis[x][y] = 1;
    ice t;
    while (!que.empty()) {
        t = que.front();
        que.pop();
        if (s[t.x][t.y] == '2') return t.step;
        for (int i = 0; i < 4; i++) {
            int nx = t.x;
            int ny = t.y;
            while (nx + dx[i] > 0 && nx + dx[i] <= n &&
                   ny + dy[i] > 0 && ny + dy[i] <= m &&
                   s[nx + dx[i]][ny + dy[i]] == '0') {
                nx += dx[i];
                ny += dy[i];
            }
            if (nx + dx[i] > 0 && nx + dx[i] <= n &&
                ny + dy[i] > 0 && ny + dy[i] <= m &&
                s[nx + dx[i]][ny + dy[i]] == '2') {
                nx += dx[i];
                ny += dy[i];
            }
            if (!vis[nx][ny]) {
                que.push({nx, ny, t.step + 1});
                vis[nx][ny] = 1;
            }
        }
    }
    return -1;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> s[i][j];
        }
    }
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    s[x2][y2] = '2';
    int ans = bfs(x1, y1);
    if (ans == -1) {
        cout << "No!God!Please no!" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}