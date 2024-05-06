#include <bits/stdc++.h>
using namespace std;
int dp[10005];
int main() {
    int N,V;
    scanf("%d%d",&N,&V);
    for(int i = 1,c,v;i <= N;++i) {
        scanf("%d%d",&c,&v);
        for(int j = c;j <= V;j++) {
            dp[j] = max(dp[j],dp[j - c] + v);
        }
    }
    printf("%d\n",dp[V]);
    return 0;
}