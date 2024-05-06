#include <bits/stdc++.h>
#define MAX_N 1000000
using namespace std;
int f[MAX_N + 5];
int dp[MAX_N + 5];
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) {
        scanf("%d",f + i);
    }
    dp[n] = 1;
    int ml;
    for(int i = n - 1;i >= 1;i--) {
        ml = 0;
        for(int j = i + 1;j <= n;j++) {
            if(f[j] > f[i] && dp[j] > ml) {
                ml = dp[j];
            }
        }
        dp[i] = ml + 1;
    }
    ml = 0;
    for(int i = 1;i <= n;i++) {
        ml = max(ml,dp[i]);
    }
    printf("%d\n",ml);
    return 0;
}