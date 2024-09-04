#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    int n;
    int ans = 0, la, d = 0x3f3f3f3f, a, cnt = 1;
    scanf("%lld%lld", &n, &la);
    for (int i = 2; i <= n; i++) {
        scanf("%lld", &a);
        if (a - la != d) {
            ans += cnt * (cnt - 1) / 2 + cnt - 1;
            cnt = 2;
            d = a - la;
        } else {
            cnt++;
        }
        la = a;
    }
    ans += cnt * (cnt - 1) / 2 + cnt;
    printf("%lld\n", ans);
    return 0;
}