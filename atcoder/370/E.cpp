#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
using ll = long long;
int a[200005];
int main() {
    ll n, k;
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    map<ll, int> cnt;
    cnt[0] = 1;
    ll ans, summ = 0, sum = 1;
    for (int i = 1; i <= n; i++) {
        summ += a[i];
        ans = (sum - cnt[summ - k] + MOD) % MOD;
        cnt[summ] = (cnt[summ] + ans) % MOD;
        sum = (sum + ans) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}