#include <bits/stdc++.h>
#define MAX_N 100000
using namespace std;
int dp[MAX_N + 5];
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 1,id,len,t;i <= n;i++) {
        scanf("%d%d",&id,&len);
        dp[i] = len;
        while(true) {
            scanf("%d",&t);
            if(t == 0) break;
            dp[i] = max(dp[i],dp[t] + len);
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        ans = max(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}