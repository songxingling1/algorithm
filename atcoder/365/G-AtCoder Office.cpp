#include <bits/stdc++.h>
#define MAX_N 200005
using namespace std;
int n, m, q, tot;
int T[MAX_N], P[MAX_N];
int ma[MAX_N], ans[1000][MAX_N];
vector<int> t[MAX_N];
int tmp[MAX_N];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &T[i], &P[i]);
        t[P[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (t[i].size() < 500) continue;
        ma[i] = ++tot;
        int f = 0;
        for (int j = 1; j <= m; j++) {
            if (f) tmp[j] = T[j] - T[j - 1];
            else tmp[j] = 0;
            if (P[j] == i) f ^= 1;
        }
        for (int j = 1; j <= m; j++) tmp[j] += tmp[j - 1];
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            for (int k = 0, l = t[j].size(); k < l;
                 k += 2) {
                ans[tot][j] +=
                    tmp[t[j][k + 1]] - tmp[t[j][k]];
            }
        }
    }
    scanf("%d", &q);
    int a, b, l1, l2, lt, f1, f2, p1, p2, ans2;
    while (q--) {
        scanf("%d%d", &a, &b);
        if (ma[a]) {
            printf("%d\n", ans[ma[a]][b]);
            continue;
        }
        if (ma[b]) {
            printf("%d\n", ans[ma[b]][a]);
            continue;
        }
        p1 = p2 = ans2 = f1 = f2 = lt = 0;
        l1 = t[a].size();
        l2 = t[b].size();
        while (p1 < l1 && p2 < l2) {
            if (t[a][p1] < t[b][p2]) {
                if (f1 && f2) ans2 += T[t[a][p1]] - lt;
                f1 ^= 1;
                lt = T[t[a][p1]];
                p1++;
            } else {
                if (f1 && f2) ans2 += T[t[b][p2]] - lt;
                f2 ^= 1;
                lt = T[t[b][p2]];
                p2++;
            }
        }
        printf("%d\n", ans2);
    }
    return 0;
}