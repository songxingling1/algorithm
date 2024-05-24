#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;
int dp[MAX_N + 5][MAX_N + 5],timee[MAX_N + 5][MAX_N + 5];
int time_cost[MAX_N + 5],rmb_cost[MAX_N + 5],rp_cost[MAX_N + 5];
int main() {
    int n,m,r;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) {
        scanf("%d%d%d",rmb_cost + i,rp_cost + i,time_cost + i);
    }
    scanf("%d%d",&m,&r);
    for(int k = 1;k <= n;k++) {
        for(int i = m;i >= rmb_cost[k];i--) {
            for(int j = r;j >= rp_cost[k];j--) {
                if(dp[i][j] < dp[i - rmb_cost[k]][j - rp_cost[k]] + 1 ||
                  (dp[i][j] == dp[i - rmb_cost[k]][j - rp_cost[k]] + 1 &&
                   timee[i][j] > timee[i - rmb_cost[k]][j - rp_cost[k]] + time_cost[k])) {
                    dp[i][j] = dp[i - rmb_cost[k]][j - rp_cost[k]] + 1;
                    timee[i][j] = timee[i - rmb_cost[k]][j - rp_cost[k]] + time_cost[k];
                }
            }
        }
    }
    printf("%d\n",timee[m][r]);
    return 0;
}