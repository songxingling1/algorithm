#include <bits/stdc++.h>
using namespace std;
int arr[60][60][60];
int vis[60][60][60];
const int dx[6] = {-1, 0, 1, 0, 0, 0};
const int dy[6] = {0, 1, 0, -1, 0, 0};
const int dz[6] = {0, 0, 0, 0, 1, -1};
int a, b, c, tt;
struct block {
    int x, y, z, step;
    block(int xx, int xy, int xz, int xstep)
    : x(xx)
    , y(xy)
    , z(xz)
    , step(xstep) {}
    block()
    : x(0)
    , y(0)
    , z(0)
    , step(0) {}
};
int bfs() {
    memset(vis, 0, sizeof(vis));
    queue<block> que;
    que.push({1, 1, 1, 0});
    vis[1][1][1] = 1;
    block t;
    while (!que.empty()) {
        t = que.front();
        que.pop();
        if (t.step > tt) {
            continue;
        }
        if (t.x == a && t.y == b && t.z == c) {
            return t.step;
        }
        for (int i = 0; i < 6; i++) {
            int newx = t.x + dx[i];
            int newy = t.y + dy[i];
            int newz = t.z + dz[i];
            if (newx > 0 && newy > 0 && newz > 0 &&
                newx <= a && newy <= b && newz <= c &&
                !arr[newx][newy][newz] &&
                !vis[newx][newy][newz]) {
                que.push({newx, newy, newz, t.step + 1});
                vis[newx][newy][newz] = 1;
            }
        }
    }
    return -1;
}
int main() {
    int k;
    scanf("%d", &k);
    while (k--) {
        scanf("%d%d%d%d", &a, &b, &c, &tt);
        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                for (int l = 1; l <= c; l++) {
                    scanf("%d", &arr[i][j][l]);
                }
            }
        }
        printf("%d\n", bfs());
    }
    return 0;
}