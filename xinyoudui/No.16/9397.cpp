#include <bits/stdc++.h>
using namespace std;
int n, m;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
char s[25][25];
int vis[26];
int ans = 0;
void dfs(int x, int y, int step) {
    ans = max(ans, step);
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx <= 0 || ny <= 0 || nx > n || ny > m ||
            vis[s[nx][ny] - 'A'])
            continue;
        vis[s[nx][ny] - 'A'] = 1;
        dfs(nx, ny, step + 1);
        vis[s[nx][ny] - 'A'] = 0;
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> s[i][j];
        }
    }
    vis[s[1][1] - 'A'] = 1;
    dfs(1, 1, 1);
    cout << ans << endl;
    return 0;
}