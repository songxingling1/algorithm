#include <bits/stdc++.h>
using namespace std;
int dp[505];
int main() {
    int n;
    scanf("%d", &n);
    dp[1] = 2;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 2 * (i - 1);
    }
    printf("%d\n", dp[n]);
    return 0;
}