#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int m[60][60];
int vis[60][60];
int vis2[60][60];
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
ll ans1, ans2, flag;
int n;
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
void bfs() {
    queue<point> que;
    que.push({1, 1, 1});
    vis[1][1] = 1;
    point t;
    while (!que.empty()) {
        t = que.front();
        que.pop();
        if (t.x == n && t.y == n) {
            ans1 = t.step;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int newx = t.x + dx[i];
            int newy = t.y + dy[i];
            if (newx > 0 && newy > 0 && newx <= n &&
                newy <= n && !m[newx][newy] &&
                !vis[newx][newy]) {
                que.push({newx, newy, t.step + 1});
                vis[newx][newy] = 1;
            }
        }
    }
}
void dfs(int nn, int x, int y) {
    if (nn == ans1) {
        if (x == n && y == n) ans2++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (newx > 0 && newy > 0 && newx <= n &&
            newy <= n && !m[newx][newy] &&
            !vis2[newx][newy]) {
            vis2[newx][newy] = 1;
            dfs(nn + 1, newx, newy);
            vis2[newx][newy] = 0;
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    if (m[1][1] == 1) {
        printf("0\n0\n");
        return 0;
    }
    bfs();
    vis2[1][1] = 1;
    dfs(1, 1, 1);
    printf("%lld\n%lld\n", ans2, ans1);
    return 0;
}