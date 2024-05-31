#include <bits/stdc++.h>
#define MAX_N 30000
using namespace std;
int n,a[MAX_N + 5];
int dp[4][MAX_N + 5];
int main() {
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) {
        scanf("%d",a + i);
    }
    long long ans = 0;
    for(int i = 1;i <= n;i++) {
        dp[1][i] = 1;
        for(int k = 2;k <= 3;k++) {
            for(int j = 1;j < i;j++) {
                if(a[j] < a[i]) {
                    dp[k][i] += dp[k - 1][j];
                }
            }
        }
        ans += dp[3][i];
    }
    printf("%lld\n",ans);
    return 0;
}