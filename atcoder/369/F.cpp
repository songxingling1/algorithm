#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using PII = pair<int, int>;
int h, w, n;
PII p[200005], dp[200005];
PII f[200005];
void modify(PII x, int pos) {
    while (pos <= w) {
        f[pos] = max(f[pos], x);
        pos += pos & -pos;
    }
}
PII query(int pos) {
    PII res{-1, 0};
    while (pos) {
        res = max(res, f[pos]);
        pos -= pos & -pos;
    }
    return res;
}
int main() {
    scanf("%d%d%d", &h, &w, &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &p[i].fi, &p[i].se);
    p[0] = {1, 1};
    p[n + 1] = {h, w};
    sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; i++) {
        f[i] = {INT_MIN, 0};
    }
    modify(dp[0], 1);
    for (int i = 1; i <= n + 1; i++) {
        dp[i] = query(p[i].se);
        modify({++dp[i].fi, i}, p[i].se);
    }
    printf("%d\n", dp[n + 1].fi - 1);
    string ans;
    for (int i = n + 1; i; i = dp[i].se) {
        for (int j = 1; j <= p[i].fi - p[dp[i].se].fi; j++)
            ans += 'D';
        for (int j = 1; j <= p[i].se - p[dp[i].se].se; j++)
            ans += 'R';
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}