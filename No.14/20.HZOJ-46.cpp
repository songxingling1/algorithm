#include <bits/stdc++.h>
#define MAX_N 1000
using namespace std;
char s[MAX_N + 5];
int dp[MAX_N + 5][MAX_N + 5] = {{0}};
int main() {
    int j;
    scanf("%s",s + 1);
    int len = strlen(s + 1);
    for(int l = 2;l <= len;l++) {
        for(int i = 1;i + l - 1 <= len;i++) {
            j = i + l - 1;
            if(s[i] == s[j] && dp[i + 1][j - 1] == 0) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = 0x3f3f3f3f;
            for(int k = i;k < j;k++) {
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[k + 1][j] + 1);
            }
        }
    }
    printf("%d\n",dp[1][len]);
    return 0;
}