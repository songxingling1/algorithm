#include <bits/stdc++.h>
#define MAX_N 400
using namespace std;
int n, m, x, y;
int ans[MAX_N + 5][MAX_N + 5];
bool vis[MAX_N + 5][MAX_N + 5] = { false };
const int mx[9] = { 0, 1, 2, 2, 1, -1, -2, -2, -1 };
const int my[9] = { 0, 2, 1, -1, -2, -2, -1, 1, 2 };
void print () {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf ("%d ", ans[i][j] == n * m + 1 ? -1 : ans[i][j]);
        }
        puts ("");
    }
}
struct data {
    int x, y, step;
};
void dfs (int x, int y) {
    queue<data> q;
    data tmp, maker;
    tmp.x = x;
    tmp.y = y;
    tmp.step = 0;
    q.push (tmp);
    vis[x][y] = true;
    while (!q.empty ()) {
        tmp = q.front ();
        q.pop ();
        ans[tmp.x][tmp.y] = tmp.step;
        for (int i = 1; i <= 8; i++) {
            int newx = tmp.x + mx[i], newy = tmp.y + my[i];
            if (newx > n || newx < 1 || newy > m || newy < 1
                || vis[newx][newy])
                continue;
            maker.step = tmp.step + 1;
            maker.x = newx;
            maker.y = newy;
            vis[newx][newy] = true;
            q.push (maker);
        }
    }
}
int main () {
    scanf ("%d%d%d%d", &n, &m, &x, &y);
    memset (ans, -1, sizeof (ans));
    dfs (x, y);
    print ();
    return 0;
}
