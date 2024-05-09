#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;
int sum[MAX_N + 5][MAX_N + 5] = {{0}};
int n;
int solve(int l,int r) {
    int s = 0,ans = 0;
    for(int i = 1;i <= n;i++) {
        if(s >= 0) s += sum[r][i] - sum[l - 1][i];
        else s = sum[r][i] - sum[l - 1][i];
        ans = max(ans,s);
    }
    return ans;
}
int main() {
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)  {
        for(int j = 1;j <= n;j++) {
            scanf("%d",&sum[i][j]);
            sum[i][j] += sum[i - 1][j];
        }
    }
    int ans = INT_MIN;
    for(int i = 1;i <= n;i++) {
        for(int j = i;j <= n;j++) {
            ans = max(ans,solve(i,j));
        }
    }
    printf("%d\n",ans);
    return 0;
}