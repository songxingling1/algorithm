#include <bits/stdc++.h>
using namespace std;
int k[250];
int vis[250];
int n, a, b;
struct f {
    int cnt, step;
    f(int a, int b)
    : cnt(a)
    , step(b) {}
    f()
    : cnt(0)
    , step(0) {}
};
int bfs() {
    queue<f> que;
    que.push({a, 0});
    vis[a] = 1;
    f t;
    while (!que.empty()) {
        t = que.front();
        que.pop();
        if (t.cnt == b) return t.step;
        if (t.cnt + k[t.cnt] <= n &&
            !vis[t.cnt + k[t.cnt]]) {
            que.push({t.cnt + k[t.cnt], t.step + 1});
            vis[t.cnt + k[t.cnt]] = 1;
        }
        if (t.cnt - k[t.cnt] > 0 &&
            !vis[t.cnt - k[t.cnt]]) {
            que.push({t.cnt - k[t.cnt], t.step + 1});
            vis[t.cnt - k[t.cnt]] = 1;
        }
    }
    return -1;
}
int main() {
    while (scanf("%d", &n)) {
        if (n == 0) break;
        scanf("%d%d", &a, &b);
        for (int i = 1; i <= n; i++) {
            scanf("%d", k + i);
        }
        memset(vis, 0, sizeof(vis));
        printf("%d\n", bfs());
    }
    return 0;
}