#include <bits/stdc++.h>
using namespace std;
char s[10][10];
int vis[10][10];
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int ans = -1;
int n, m;
void dfs(int x, int y, int jia) {
    if (s[x][y] != '*' && s[x][y] != '#') {
        jia += s[x][y] - '0';
    }
    if (x == n && y == m) {
        ans = max(ans, jia);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx <= 0 || ny <= 0 || nx > n || ny > m ||
            vis[nx][ny] || s[nx][ny] == '#')
            continue;
        vis[nx][ny] = 1;
        dfs(nx, ny, jia);
        vis[nx][ny] = 0;
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> s[i][j];
        }
    }
    vis[1][1] = 1;
    dfs(1, 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '#') {
                s[i][j] = '*';
                dfs(1, 1, 0);
                s[i][j] = '#';
            }
        }
    }
    cout << ans << endl;
    return 0;
}