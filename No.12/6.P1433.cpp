#include <bits/stdc++.h>
#define MAX_N 15
using namespace std;
int n;
bitset<MAX_N + 5> vis;
double mx[MAX_N + 5], my[MAX_N + 5];
double dp[1 << (MAX_N + 1)][MAX_N + 1];          // NOLINT
double dis[MAX_N + 5][MAX_N + 5];
int ind[1 << (MAX_N + 1)];          // NOLINT
inline double getNum (double sx, double sy, double wx, double wy) {
    return sqrt ((sx - wx) * (sx - wx) + (sy - wy) * (sy - wy));
}
double ans = 0x3f3f3f3f;
void dfs (int step = 0, double sum = 0, int id = 0) {
    if (dp[vis.to_ulong ()][id] < sum || sum > ans)
        return;
    if (step == n) {
        if (sum < ans)
            ans = sum;
        return;
    }
    dp[vis.to_ulong ()][id] = sum;
    int i;
    for (unsigned long k = vis.to_ulong (); k; k -= (k & -k)) {
        i = ind[k & -k];
        vis.set (i, false);
        dfs (step + 1, sum + dis[id][i], i);
        vis.set (i, true);
    }
}
int main () {
    scanf ("%d", &n);
    mx[0] = my[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf ("%lf%lf", &mx[i], &my[i]);
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dis[i][j] = getNum (mx[i], my[i], mx[j], my[j]);
        }
    }
    for (int k = 1, i = 0; i <= n; i++, k *= 2) {
        ind[k] = i;
        vis.set (i, true);
    }
    vis.set (0, false);
    memset (dp, 127, sizeof (dp));
    dfs ();
    printf ("%.2f\n", ans);
    return 0;
}
