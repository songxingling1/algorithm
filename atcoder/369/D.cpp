#include <bits/stdc++.h>
using namespace std;
long long dp[200005][2];
signed main() {
    int n;
    scanf("%d", &n);
    dp[0][1] = -0x3f3f3f3f;
    for (int i = 1, a; i <= n; i++) {
        scanf("%d", &a);
        for (int j = 0; j <= 1; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            dp[i][1 - j] = max(dp[i][1 - j],
                               dp[i - 1][j] + a * (j + 1));
        }
    }
    printf("%lld\n", max(dp[n][0], dp[n][1]));
    return 0;
}