#include <bits/stdc++.h>
#define MAX_N 200000
using namespace std;
int dp[MAX_N + 5];
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) {
        scanf("%d",&dp[i]);
    }
    int S = 0,ans = INT_MIN;
    for(int i = 1;i <= n;i++) {
        if(S >= 0) {
            S += dp[i];
        } else {
            S = dp[i];
        }
        ans = max(ans,S);
    }
    printf("%d\n",ans);
    return 0;
}