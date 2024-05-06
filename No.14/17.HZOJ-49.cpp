#include <bits/stdc++.h>
using namespace std;
int dp[100005];
int main() {
    int V,n;
    scanf("%d%d",&V,&n);
    for(int i = 1,v,w,s;i <= n;i++) {
        scanf("%d%d%d",&v,&w,&s);
        for(int k = 1;k <= s;k++) {
            for(int j = V;j >= v;j--) {
                dp[j] = max(dp[j],dp[j - v] + w);
            }
        }
    }
    printf("%d\n",dp[V]);
    return 0;
}