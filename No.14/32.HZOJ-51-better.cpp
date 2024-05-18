#include <bits/stdc++.h>
#define MAX_N 1000
using namespace std;
int dp[MAX_N + 5] = {0};
int f[MAX_N + 5][MAX_N + 5] = {{0}};
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            scanf("%d",&f[i][j]);
        }
    }
    for(int i = n - 1;i >= 1;i--) {
        for(int j = 1;j <= m;j++) {
            if(f[i][j] == 0) continue;
            f[i][j] += f[i + 1][j];
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = m;j >= 1;j--) {
            int k = j;
            while(k <= m && f[i][k] >= f[i][j]) k++;
            dp[j] = f[i][j] * (k - j) + dp[k];
            ans = (ans + dp[j]) % 100007;
        }
    }
    printf("%d\n",ans);
    return 0;
}