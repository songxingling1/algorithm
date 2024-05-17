#include <bits/stdc++.h>
using namespace std;
int dp[100005];
int main() {
    int V,n;
    scanf("%d%d",&V,&n);
    for(int i = 1,v,w,s;i <= n;i++) {
        scanf("%d%d%d",&v,&w,&s);
        for(int k = 1;s >= k;s -= k,k *= 2) {
            for(int j = V;j >= v * k;j--) {
                dp[j] = max(dp[j],dp[j - v * k] + w * k);
            }
        }
        if(s != 0) {
            for(int j = V;j >= v * s;j--) {
                dp[j] = max(dp[j],dp[j - v * s] + w * s);
            }
        }
    }
    printf("%d\n",dp[V]);
    return 0;
}