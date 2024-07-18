#include <bits/stdc++.h>
using namespace std;
int a[1005];
int dp[1005];
const int MOD = 1e9 + 7;
int main() {
    int n, d;
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    sort(a + 1, a + 1 + n, greater<int>());
    dp[1] = 1;
    int cnt = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[i] <= a[j] - d) {
                dp[i] = (dp[i] + dp[j]) % MOD;
            }
        }
        cnt = (cnt + dp[i]) % MOD;
    }
    printf("%d\n", cnt);
    return 0;
}