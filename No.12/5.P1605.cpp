#include <bits/stdc++.h>
#define MAX_N 5
using namespace std;
bool vis[MAX_N + 5][MAX_N + 5];
int ans[MAX_N + 5][MAX_N + 5];
const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };
int n, m, t;
void dfs (int x, int y) {
    ans[x][y]++;
    int newx, newy;
    for (int i = 0; i < 4; i++) {
        newx = x + dx[i];
        newy = y + dy[i];
        if (newx > n || newx < 1 || newy > m || newy < 1
            || vis[newx][newy])
            continue;
        vis[newx][newy] = true;
        dfs (newx, newy);
        vis[newx][newy] = false;
    }
}
int main () {
    scanf ("%d%d%d", &n, &m, &t);
    int sx, sy, fx, fy;
    scanf ("%d%d%d%d", &sx, &sy, &fx, &fy);
    for (int i = 1, x, y; i <= t; i++) {
        scanf ("%d%d", &x, &y);
        vis[x][y] = true;
    }
    vis[sx][sy] = true;
    dfs (sx, sy);
    printf ("%d\n", ans[fx][fy]);
    return 0;
}
