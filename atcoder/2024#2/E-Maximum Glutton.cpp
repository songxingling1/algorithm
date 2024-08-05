#include <bits/stdc++.h>
using namespace std;
int dp[100][10005];
int main() {
    int a, b, n, x, y;
    int ans = 0;
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = 0x3f3f3f3f;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a, &b);
        for (int j = n; j >= 1; j--) {
            for (int k = x; k >= a; k--) {
                if (dp[j - 1][k - a] + b <= y) {
                    dp[j][k] =
                        min(dp[j][k], dp[j - 1][k - a] + b);
                }
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            if (dp[i][j] <= y) {
                ans = max(ans, i + 1);
            }
        }
    }
    ans = min(ans, n);
    printf("%d\n", ans);
    return 0;
}