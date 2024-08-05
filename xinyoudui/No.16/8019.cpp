#include <bits/stdc++.h>
using namespace std;
int xx[15];
int yy[15];
int vis[15];
int ans = 0;
int n;
void dfs(int cnt, int x, int y, int hs) {
    if (cnt == n) {
        ans++;
    }
    int mhs;  // sx->bx : 1  bx->sm : 2  sy->by : 3  by->sy : 4  else : 5
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && (x == xx[i] || y == yy[i])) {
            if (y == yy[i] && x < xx[i]) {
                mhs = 1;
            } else if (y == yy[i] && x > xx[i]) {
                mhs = 2;
            } else if (x == xx[i] && y < yy[i]) {
                mhs = 3;
            } else if (x == xx[i] && y > yy[i]) {
                mhs = 4;
            } else {
                mhs = 5;
            }
            if (mhs == hs) continue;
            vis[i] = 1;
            dfs(cnt + 1, xx[i], yy[i], mhs);
            vis[i] = 0;
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", xx + i, yy + i);
    }
    dfs(0, 0, 0, 0);
    printf("%d\n", ans);
    return 0;
}