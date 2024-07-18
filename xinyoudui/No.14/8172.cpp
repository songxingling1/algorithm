#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[100005];
int main() {
    int n;
    scanf("%d", &n);
    dp[1] = 1;
    ll add1 = 4, add2 = 4, add3 = 2;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + add1;
        add1 += add2;
        add2 += add3;
        if (add3 == 2) add3 = 1;
        else add3 = 2;
    }
    printf("%lld\n", dp[n]);
    return 0;
}