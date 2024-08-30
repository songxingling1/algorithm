#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, qwq;
int a[1000005];
int s[1000005];
int maxd = 1;
int ans = 0;
void build(int l, int r, int f) {
    if (l == r) {
        s[l] = 2 * maxd - maxd / f;
        ans += a[l] * s[l];
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, f * 2);
    build(mid + 1, r, f * 2);
}
int gcd(int a, int b) {
    int tmp;
    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
signed main() {
    scanf("%lld%lld%lld", &n, &m, &qwq);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
    }
    while (maxd <= n) maxd *= 2;
    build(1, n, 1);
    for (int i = 1; i <= n; i++) {
        s[i] += s[i - 1];
    }
    int l, r, x;
    int tmp = gcd(maxd, qwq);
    maxd /= tmp;
    qwq /= tmp;
    while (m--) {
        scanf("%lld%lld%lld", &l, &r, &x);
        ans += x * (s[r] - s[l - 1]);
        printf("%lld\n", ans / maxd * qwq);
    }
    return 0;
}