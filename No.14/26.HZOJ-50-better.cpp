#include <bits/stdc++.h>
#define MAX_N 32
#define MAX_K 1000
using namespace std;
typedef long long ll;
ll dp[MAX_N + 5][MAX_K + 5];
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++) {
        dp[i][1] = 1;
    }
    for(int i = 1;i <= n;i++) {
        for(int k = 2;k <= MAX_K;k++) {
            dp[i][k] = dp[i][k - 1] + dp[i - 1][k - 1] + 1;
        }
    }
    int ans = n;
    for(int i = 1;i <= MAX_K;i++) {
        if(dp[n][i - 1] < m &&m <= dp[n][i]) {
            ans = i;
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}