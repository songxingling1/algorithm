#include <bits/stdc++.h>
using namespace std;
int dp[5005][55];
int temp[105];
int K,V,N;
void merge(int *dest,int *src1,int *src2,int w) {
    int k1 = 1,k2 = 1,t = 1;
    int n1 = src1[0],n2 = src2[0];
    while(k1 <= n1 || k2 <= n2) {
        if(k2 > n2 || (k1 <= n1 && src1[k1] >= src2[k2] + w)) {
            temp[t++] = src1[k1++];
        } else {
            temp[t++] = src2[k2++] + w;
        }
        if(t > K) break;
    }
    temp[0] = t - 1;
    memcpy(dest,temp,sizeof(int) * (t));
}
int main() {
    scanf("%d%d%d",&K,&V,&N);
    int v,w;
    dp[0][0] = 1;
    dp[0][1] = 0;
    for(int i = 1;i <= N;i++) {
        scanf("%d%d",&v,&w);
        for(int j = V;j >= v;j--) {
            merge(dp[j],dp[j],dp[j - v],w);
        }
    }
    int ans = 0;
    for(int i = 1;i <= K;i++) {
        ans += dp[V][i];
    }
    printf("%d\n",ans);
    return 0;
}