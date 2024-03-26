#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;
int n;
int b[MAX_N + 5][MAX_N + 5];
int sum[MAX_N + 5][MAX_N + 5] = {{0}};
int solve(int left,int right){
    int ans = INT_MIN,s = 0;
    for(int i = 1;i <= n;i++) {
        if(s >= 0) s += sum[i][right] - sum[i][left - 1];
        else s = sum[i][right] - sum[i][left - 1];
        ans = max(ans,s);
    }
    return ans;
}
int main() {
    scanf("%d", &n);
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            scanf("%d",&b[i][j]);
            sum[j][i] = sum[j][i - 1] + b[i][j];
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