#include <bits/stdc++.h>
#include <climits>
#include <cstdio>
using namespace std;
using ll = long long;
ll dis[405][405];
ll u[200005], v[200005], w[200005];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; i++) {
        dis[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%lld%lld%lld", &u[i], &v[i], &w[i]);
        dis[v[i]][u[i]] = dis[u[i]][v[i]] =
            min(dis[u[i]][v[i]], w[i]);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] =
                    min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int k, id[6];
        scanf("%d", &k);
        for (int i = 1; i <= k; i++) {
            scanf("%d", id + i);
        }
        sort(id + 1, id + 1 + k);
        ll ans = LLONG_MAX;
        do {
            for (int j = 0; j < (1 << k); j++) {
                ll cur = 0;
                for (int i = 1; i <= k; i++) {
                    cur += w[id[i]];
                }
                for (int i = 1; i <= k + 1; i++) {
                    cur += dis[i == 1 ? 1
                               : (j >> (i - 2)) & 1
                                   ? v[id[i - 1]]
                                   : u[id[i - 1]]]
                              [i > k ? n
                               : (j >> (i - 1)) & 1
                                   ? u[id[i]]
                                   : v[id[i]]];
                }
                ans = min(ans, cur);
            }
        } while (next_permutation(id + 1, id + 1 + k));
        printf("%lld\n", ans);
    }
    return 0;
}