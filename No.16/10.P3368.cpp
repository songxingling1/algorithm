#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
using namespace std;
typedef long long ll;
ll a[500005];
ll c[500005];
void add(int pos1, int pos2, ll x, int n) {
    a[pos1] += x;
    while (pos1 <= n) {
        c[pos1] += x;
        pos1 += lowbit(pos1);
    }
    pos2++;
    a[pos2] -= x;
    while (pos2 <= n) {
        c[pos2] -= x;
        pos2 += lowbit(pos2);
    }
}
ll query(int x) {
    ll sum = 0;
    while (x) {
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}
int main() {
    int n, m;
    ll t, x, y, k;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &t);
        add(i, i, t, n);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%lld", &t);
        if (t == 1) {
            scanf("%lld%lld%lld", &x, &y, &k);
            add(x, y, k, n);
        } else {
            scanf("%lld", &x);
            printf("%lld\n", query(x));
        }
    }
    return 0;
}