#include <bits/stdc++.h>
using namespace std;
char s[10][300];
int vis[10][300];
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int r, c, as, aw;
void bfs(int x, int y) {
    int sheep = 0, awo = 0;
    queue<pair<int, int>> que;
    que.push({x, y});
    vis[x][y] = 1;
    if (s[x][y] == 'o') {
        sheep++;
    } else if (s[x][y] == 'v') {
        awo++;
    }
    pair<int, int> t;
    while (!que.empty()) {
        t = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int newx = t.first + dx[i],
                newy = t.second + dy[i];
            if (s[newx][newy] != '#' && !vis[newx][newy] &&
                newx > 0 && newx <= r && newy > 0 &&
                newy <= c) {
                vis[newx][newy] = 1;
                que.push({newx, newy});
                if (s[newx][newy] == 'o') {
                    sheep++;
                } else if (s[newx][newy] == 'v') {
                    awo++;
                }
            }
        }
    }
    if (sheep > awo) {
        as += sheep;
    } else {
        aw += awo;
    }
}
int main() {
    scanf("%d%d", &r, &c);
    for (int i = 1; i <= r; i++) {
        scanf("%s", s[i] + 1);
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (s[i][j] != '#' && !vis[i][j]) {
                bfs(i, j);
            }
        }
    }
    printf("%d %d\n", as, aw);
    return 0;
}