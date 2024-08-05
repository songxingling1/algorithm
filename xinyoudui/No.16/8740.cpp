#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll, ll> a;
ll dfs(ll n) {
    if (a.find(n) != a.end()) return a[n];
    ll sum = 1;
    for (ll i = 2; i <= n / 2; i++) {
        if (n % i == 0) sum += dfs(n / i);
    }
    a[n] = sum;
    return sum;
}
int main() {
    ll n;
    scanf("%lld", &n);
    printf("%lld\n", dfs(n));
    return 0;
}
