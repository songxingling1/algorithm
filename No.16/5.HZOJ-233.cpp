#include <bits/stdc++.h>
using namespace std;
int x[10005];
int main() {
    int n, p, h, m;
    scanf("%d%d%d%d", &n, &p, &h, &m);
    x[1] = h;
    set<pair<int, int>> s;
    for (int i = 1, u, v; i <= m; i++) {
        scanf("%d%d", &u, &v);
        if (u > v) swap(u, v);
        if (s.find({u, v}) != s.end()) continue;
        x[u + 1]--;
        x[v]++;
        s.insert({u, v});
    }
    for (int i = 1, cnt = 0; i <= n; i++) {
        cnt += x[i];
        printf("%d\n", cnt);
    }
    return 0;
}