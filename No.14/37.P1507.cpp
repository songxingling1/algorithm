#include <bits/stdc++.h>
#define MAX_H 400
using namespace std;
int dp[MAX_H + 5][MAX_H + 5];
int main() {
    int N,H,T;
    scanf("%d%d%d",&H,&T,&N);
    for(int l = 1,h,t,k;l <= N;l++) {
        scanf("%d%d%d",&h,&t,&k);
        for(int i = H;i >= h;i--) {
            for(int j = T;j >= t;j--) {
                dp[i][j] = max(dp[i][j],dp[i - h][j - t] + k);
            }
        }
    }
    printf("%d\n",dp[H][T]);
    return 0;
}