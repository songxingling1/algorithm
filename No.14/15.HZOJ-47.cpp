#include <bits/stdc++.h>
using namespace std;
int dp[10005];
int main() {
    int V,n;
    scanf("%d%d",&V,&n);
    for(int i = 1,v,w;i <= n;i++) {
        scanf("%d%d",&v,&w);
        for(int j = V;j >= v;j--) {
            dp[j] = max(dp[j],dp[j - v] + w);
        }
    }
    printf("%d\n",dp[V]);
    return 0;
}