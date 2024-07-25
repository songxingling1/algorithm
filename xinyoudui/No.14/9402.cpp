#include <bits/stdc++.h>
using namespace std;
int dp[100005];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(k, i); j++) {
            dp[i] = (dp[i] + dp[i - j]) % 1000000007;
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}