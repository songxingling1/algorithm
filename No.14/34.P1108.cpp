#include <bits/stdc++.h>
#define MAX_N 5000
using namespace std;
int val[MAX_N + 5] = {0x3f3f3f3f},dp[MAX_N + 5];
int last[MAX_N + 5];
int answer = 0,cnt = 0;
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) {
        scanf("%d",val + i);
    }
    int k;
    last[0] = 1;
    for(int i = 1;i <= n;i++) {
        k = 0;
        for(int j = 0;j < i;j++) {
            if(val[j] > val[i] && dp[j] > dp[k]) {
                k = j;
            }
        }
        dp[i] = dp[k] + 1;
        for(int j = 0;j < i;j++) {
            if(val[j] > val[i] && dp[j] + 1 == dp[i]) {
                last[i] += last[j];
            } else if(val[j] == val[i] && dp[j] == dp[i]) {
                last[j] = 0;
            }
        }
        answer = max(answer,dp[i]);
    }
    for(int i = 1;i <= n;i++) {
        if(dp[i] == answer) cnt += last[i];
    }
    printf("%d %d\n",answer,cnt);
    return 0;
}