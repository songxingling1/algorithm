#include <bits/stdc++.h>
#define S(x) ((x) * (x))
#define FOR(x,l,r) for(int x = l;x <= r;x++)
#define INF 0x3f3f3f3f
using namespace std;
int val[10][10] = {{0}};
int dp[20][10][10][10][10] = {{{{{0}}}}};
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= 8;i++) {
        for(int j = 1;j <= 8;j++) {
            scanf("%d",&val[i][j]);
            val[i][j] += val[i - 1][j] + val[i][j - 1] - val[i - 1][j - 1];
        }
    }
    FOR(i,1,8) {
        FOR(j,1,8) {
            FOR(k,i,8) {
                FOR(l,j,8) {
                    dp[1][i][j][k][l] = S(val[k][l] - val[i - 1][l] - val[k][j - 1] + val[i - 1][j - 1]);
                }
            }
        }
    }
    FOR(t,2,n) {
        FOR(i,1,8) {
            FOR(j,1,8) {
                FOR(k,i,8) {
                    FOR(l,j,8) {
                        int ans = INF;
                        FOR(c,j,l - 1) {
                            int val1 = dp[1][i][j][k][c] + dp[t - 1][i][c + 1][k][l];
                            int val2 = dp[t - 1][i][j][k][c] + dp[1][i][c + 1][k][l];
                            ans = min(ans,min(val1,val2));
                        }
                        FOR(c,i,k - 1) {
                            int val1 = dp[1][i][j][c][l] + dp[t - 1][c + 1][j][k][l];
                            int val2 = dp[t - 1][i][j][c][l] + dp[1][c + 1][j][k][l];
                            ans = min(ans,min(val1,val2));
                        }
                        dp[t][i][j][k][l] = ans;
                    }
                }
            }
        }
    }
    printf("%d\n",dp[n][1][1][8][8]);
    return 0;
}