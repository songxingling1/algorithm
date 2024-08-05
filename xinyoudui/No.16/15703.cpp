#include <bits/stdc++.h>
#define JUDGE                                              \
    s[i][j] != '.' && s[i][j] != 'F' && s[i][j] != '@' &&  \
        s[i][j] != '&' && s[i][j] != '#'
using namespace std;
char s[250][250];
int vis[250][250];
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int n, m;
struct point {
    int x, y, step;
    point(int a, int b, int c)
    : x(a)
    , y(b)
    , step(c) {}
    point()
    : x(0)
    , y(0)
    , step(0) {}
};
int bfs(int x, int y) {
    queue<point> que;
    que.push({x, y, 0});
    vis[x][y] = 1;
    point t;
    while (!que.empty()) {
        t = que.front();
        que.pop();
        if (s[t.x][t.y] == 'F') {
            return t.step;
        }
        for (int i = 0; i < 4; i++) {
            int newx = t.x + dx[i];
            int newy = t.y + dy[i];
            if (newx > 0 && newy > 0 && newx <= n &&
                newy <= m && !vis[newx][newy] &&
                s[newx][newy] != '#' && t.step <= 179) {
                que.push({newx, newy, t.step + 1});
                vis[newx][newy] = 1;
            }
        }
    }
    return -1;
}
int main() {
    int fx, fy, sx, sy;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> s[i][j];
            if (s[i][j] == '@') {
                fx = i;
                fy = j;
            } else if (s[i][j] == '&') {
                sx = i;
                sy = j;
            }
        }
    }
    int a = bfs(fx, fy);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            vis[i][j] = 0;
        }
    }
    int b = bfs(sx, sy);
    if (a == -1 || b == -1) {
        printf("Meeting cancelled\n");
    } else {
        printf("%d\n", max(a, b));
    }
    return 0;
}