#include <bits/stdc++.h>
using namespace std;
int dp[1005];
int main() {
    int n;
    scanf("%d", &n);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % 12345;
    }
    printf("%d\n", dp[n]);
    return 0;
}