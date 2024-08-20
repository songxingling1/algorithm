#include <bits/stdc++.h>
#define lowbit(x) ((x) & -(x))
using namespace std;
using LL = long long;
int a[200005];
LL t[200005];
LL l[200005], r[200005];
int n;
void add(int pos, int x) {
    while (pos <= n) t[pos] += x, pos += lowbit(pos);
}
LL query(int pos) {
    LL ans = 0;
    while (pos) {
        ans += t[pos];
        pos -= lowbit(pos);
    }
    return ans;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) {
        add(a[i], 1);
        l[i] = query(a[i] - 1);
    }
    memset(t, 0, sizeof(t));
    LL la = 0, ra = 0;
    for (int i = n; i >= 1; i--) {
        add(a[i], 1);
        r[i] = query(a[i] - 1);
        la += l[i] * r[i];
        ra += (i - l[i] - 1) * (n - i - r[i]);
    }
    printf("%lld %lld\n", ra, la);
    return 0;
}