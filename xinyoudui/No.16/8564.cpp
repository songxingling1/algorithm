#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
char s[30][30];
int vis[30][30];
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int t, w, h, x, y;
int bfs(int x, int y) {
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int>> que;
    que.push({x, y});
    vis[x][y] = 1;
    int ans = 1;
    pair<int, int> tmp;
    while (!que.empty()) {
        tmp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int newx = tmp.first + dx[i];
            int newy = tmp.second + dy[i];
            if (newx > 0 && newy > 0 && newx <= w &&
                newy <= h && s[newx][newy] != '#' &&
                !vis[newx][newy]) {
                que.push({newx, newy});
                vis[newx][newy] = 1;
                ans++;
            }
        }
    }
    return ans;
}
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &h, &w);
        for (int i = 1; i <= w; i++) {
            getchar();
            for (int j = 1; j <= h; j++) {
                scanf("%c", &s[i][j]);
                if (s[i][j] == '@') {
                    x = i;
                    y = j;
                }
            }
        }
        printf("%d\n", bfs(x, y));
    }
    return 0;
}