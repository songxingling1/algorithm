#include <bits/stdc++.h>
using namespace std;
char a[105][105];
int vis[105][105];
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int n, m;
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
struct cmp {
    bool operator()(const block a, const block b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    }
};
map<block, block, cmp> ma;
int bfs() {
    queue<block> que;
    que.push({1, 1, 0});
    vis[1][1] = 1;
    block t, t2;
    while (!que.empty()) {
        t = que.front();
        que.pop();
        if (t.x == n && t.y == m) {
            return t.step;
        }
        for (int i = 0; i < 4; i++) {
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];
            if (ma.find({nx, ny, 0}) != ma.end()) {
                t2 = ma[{nx, ny, 0}];
                nx = t2.x;
                ny = t2.y;
            }
            if (nx > 0 && ny > 0 && nx <= n && ny <= m &&
                !vis[nx][ny] && a[nx][ny] != '1') {
                que.push({nx, ny, t.step + 1});
                vis[nx][ny] = 1;
            }
        }
    }
    return -1;
}
int main() {
    map<char, block> tmp;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] != '0' && a[i][j] != '1') {
                if (tmp.find(a[i][j]) != tmp.end()) {
                    ma[{tmp[a[i][j]].x,
                        tmp[a[i][j]].y,
                        0}] = {i, j, 0};
                    ma[{i, j, 0}] = {
                        tmp[a[i][j]].x, tmp[a[i][j]].y, 0};
                } else {
                    tmp[a[i][j]] = {i, j, 0};
                }
            }
        }
    }
    int ans = bfs();
    if (ans == -1) {
        cout << "No Solution." << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}