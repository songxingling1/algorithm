#include <bits/stdc++.h>
#define MAX_N 1000
using namespace std;
char s1[MAX_N + 5],s2[MAX_N + 5];
int dp[MAX_N + 5][MAX_N + 5];
int main() {
    scanf("%s",s1 + 1);
    scanf("%s",s2 + 1);
    int len1 = strlen(s1 + 1),len2 = strlen(s2 + 1);
    for(int i = 1;i <= len1;i++) {
        for(int j = 1;j <= len2;j++) {
            if(s1[i] == s2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j - 1],max(dp[i][j - 1],dp[i - 1][j]));
            }
        }
    }
    printf("%d\n",dp[len1][len2]);
    return 0;
}