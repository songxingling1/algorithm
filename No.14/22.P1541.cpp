#include <bits/stdc++.h>
#define MAX_N 350
#define MAX_M 40
using namespace std;
int A[MAX_N + 5] = {0},B[5] = {0},dp[MAX_M + 5][MAX_M + 5][MAX_M + 5] = {{{0}}};
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++) {
        scanf("%d",A + i);
    }
    for(int i = 1,t;i <= m;i++) {
        scanf("%d",&t);
        B[t]++;
    }
    for(int a = 0;a <= B[1];a++) {
        for(int b = 0;b <= B[2];b++) {
            for(int c = 0;c <= B[3];c++) {
                for(int d = 0;d <= B[4];d++) {
                    int ans = dp[b][c][d];
                    if(b) ans = max(ans,dp[b - 1][c][d]);
                    if(c) ans = max(ans,dp[b][c - 1][d]);
                    if(d) ans = max(ans,dp[b][c][d - 1]);
                    dp[b][c][d] = A[a + 2 * b + 3 * c + 4 * d + 1] + ans;
                }
            }
        }
    }
    printf("%d\n",dp[B[2]][B[3]][B[4]]);
    return 0;
}