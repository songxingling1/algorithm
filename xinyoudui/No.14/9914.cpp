#include <bits/stdc++.h>
using namespace std;
int a[1005], b[1005], dp[1005];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", a + i, b + i);
    }
    dp[1] = a[1];
    int cnt;
    for (int i = 2; i <= n; i++) {
        cnt = 0;
        dp[i] = 0x3f3f3f3f;
        for (int j = i; j >= 1; j--) {
            dp[i] = min(dp[i], a[j] + cnt);
            cnt += b[j - 1];
        }
        dp[i] += dp[i - 1];
    }
    printf("%d\n", dp[n]);
    return 0;
}