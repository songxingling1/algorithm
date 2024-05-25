#include <bits/stdc++.h>
#define MAX_N 1000
using namespace std;
int x[MAX_N + 5];
int dp[MAX_N + 5][MAX_N + 5];

int clac(int i,int j) {
    if(i == j) {
        return x[i];
    } else {
        return abs(x[i] - x[j]) * (j - i + 1);
    }
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) {
        scanf("%d",x + i);
    }
    int j;
    for(int l = n;l >= 0;l--) {
        for(int i = 1;i + l - 1 <= n;i++) {
            j = i + l - 1;
            for(int k = 1;k < i;k++) {
                dp[i][j] = max(dp[i][j],dp[i - k][j] + clac(i - k,i - 1));
            }
            for(int k = 1;k <= n - j;k++) {
                dp[i][j] = max(dp[i][j],dp[i][j + k] + clac(j + 1,j + k));
            }
        }
    }
#ifdef DEBUG
    for(int j = 0;j <= n;j++) {
        if(j == 0) {
            printf("    | ");
            continue;
        }
        printf("%4d ",j);
    }
    puts("");
    for(int j = 0;j <= n;j++) {
        if(j == 0) {
            printf("----|-");
            continue;
        }
        printf("-----");
    }
    puts("");
    for(int i = 1;i <= n + 1;i++) {
        for(int j = 0;j <= n;j++) {
            if(j == 0) {
                printf("%4d| ",i);
                continue;
            }
            printf("%4d ",dp[i][j]);
        }
        puts("");
    }
#endif
    int ans = 0;
    for(int i = 1;i <= n + 1;i++) {
        ans = max(ans,dp[i][i - 1]);
    }
    printf("%d\n",ans);
    return 0;
}