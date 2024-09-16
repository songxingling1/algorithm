#include <bits/stdc++.h>
#include <climits>
using namespace std;
using ll = long long;
ll ans, tot;
char s[2000006];
int nt[2000006], w[2000006];
int n;
void solve() {
    int l = 0, nn = -1;
    tot = 0;
    for (int i = n << 1; i; i--) {
        if (s[i] == 'B') nt[i] = l, l = i;
        else nt[i] = 0;
    }
    if (l == 0) {
        ans = 0;
        return;
    }
    for (int i = 1; i <= 2 * n; i++) {
        w[i] = w[i - 1] + (s[i] == 'R');
    }
    for (int i = l; i <= n; i = nt[i]) {
        if (w[i] <= w[n] - w[i - 1]) nn = i, tot += w[i];
        else break;
    }
    if (nn == -1) {
        ans = 0;
        return;
    }
    for (int i = nt[nn]; i <= n; i = nt[i]) {
        tot += w[n] - w[i - 1];
    }
    ans = min(ans, tot);
    for (int i = 2; i <= n; i++) {
        if (s[i - 1] == 'R')
            tot -= nn - i + 1 - w[nn] + w[i - 1];
        if (s[i + n - 1] == 'R')
            tot += i + n - 1 - nn - w[n + i - 1] + w[nn];
        while (nt[nn] && w[nt[nn]] - w[i - 1] <=
                             w[i + n - 1] - w[nt[nn]]) {
            nn = nt[nn];
            tot -= w[i + n - 1] - w[nn];
            tot += w[nn] - w[i - 1];
        }
        ans = min(tot, ans);
    }
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ans = LLONG_MAX;
        scanf("%s", s + 1);
        n = strlen(s + 1);
        for (int i = 1; i <= n; i++) s[i + n] = s[i];
        solve();
        printf("%lld\n", ans);
    }
    return 0;
}