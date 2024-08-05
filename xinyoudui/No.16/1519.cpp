#include <bits/stdc++.h>
using namespace std;
int ma[100][100][100];
int vis[100][100][100];
const int dx[6] = {-1, 0, 1, 0, 0, 0};
const int dy[6] = {0, 1, 0, -1, 0, 0};
const int dz[6] = {0, 0, 0, 0, 1, -1};
int l, w, h, m, ans;
struct block {
    int x, y, z;
    block(int xx, int xy, int xz)
    : x(xx)
    , y(xy)
    , z(xz) {}
    block()
    : x(0)
    , y(0)
    , z(0) {}
};
void bfs(int x, int y, int z) {
    queue<block> que;
    que.push({x, y, z});
    vis[x][y][z] = 1;
    block t;
    while (!que.empty()) {
        t = que.front();
        que.pop();
        for (int i = 0; i < 6; i++) {
            int newx = t.x + dx[i];
            int newy = t.y + dy[i];
            int newz = t.z + dz[i];
            if (newx > 0 && newy > 0 && newz > 0 &&
                newx <= l && newy <= w && newz <= h &&
                abs(ma[newx][newy][newz] -
                    ma[t.x][t.y][t.z]) <= m &&
                !vis[newx][newy][newz]) {
                que.push({newx, newy, newz});
                vis[newx][newy][newz] = 1;
            }
        }
    }
}
int main() {
    scanf("%d%d%d%d", &l, &w, &h, &m);
    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= w; j++) {
            for (int k = 1; k <= h; k++) {
                scanf("%d", &ma[i][j][k]);
            }
        }
    }
    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= w; j++) {
            for (int k = 1; k <= h; k++) {
                if (!vis[i][j][k]) {
                    bfs(i, j, k);
                    ans++;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}