#include <bits/stdc++.h>
#define MAX_N 200005
using namespace std;
using LL = long long;
int a[MAX_N];
LL solve(int k, int n) {
    vector<int> odd(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        odd[i] = (a[i] >> k) & 1;
    }
    for (int i = 2; i <= n; i++) {
        odd[i] ^= odd[i - 1];
    }
    LL ans = 0;
    int m[2] = {1, 0};
    for (int i = 1; i <= n; i++) {
        ans += m[odd[i] ^ 1];
        m[odd[i]]++;
    }
    return ans;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    LL ans = 0;
    for (int i = 0; i <= 31; i++) {
        ans += (1LL << i) * solve(i, n);
    }
    for (int i = 1; i <= n; i++) {
        ans -= a[i];
    }
    printf("%lld\n", ans);
    return 0;
}