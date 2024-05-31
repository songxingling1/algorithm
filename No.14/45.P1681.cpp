#include <bits/stdc++.h>
#define MAX_N 1500
using namespace std;
int dp[MAX_N + 5][MAX_N + 5];
int val[MAX_N + 5][MAX_N + 5];
int h[MAX_N + 5][MAX_N + 5],w[MAX_N + 5][MAX_N + 5];
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    dp[1][1] = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            scanf("%d",&val[i][j]);
            h[i][j] = 1;
            w[i][j] = 1;
            if(val[i][j] != val[i][j - 1] && val[i][j] != val[i - 1][j]) {
                h[i][j] = h[i - 1][j] + 1;
                w[i][j] = w[i][j - 1] + 1;
            }
        }
    }
    int ans = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(i == 1 && j == 1) continue;
            dp[i][j] = min(dp[i - 1][j - 1] + 1,min(h[i][j],w[i][j]));
            ans = max(ans,dp[i][j]);
        }
    }
    printf("%d\n",ans);
    return 0;
}