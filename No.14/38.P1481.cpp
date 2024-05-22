#include <bits/stdc++.h>
using namespace std;
char s[2005][80];
int dp[2005];
vector<int> v[2005];
bool isSubstr(int i,int j) {
    int len1 = strlen(s[i]),len2 = strlen(s[j]);
    if(len1 > len2) return false;
    for(int k = 0;k < len1;k++) {
        if(s[i][k] != s[j][k]) return false;
    }
    return true;
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) {
        scanf("%s",s[i]);
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j < i;j++) {
            if(isSubstr(j,i)) {
                v[i].push_back(j);
            }
        }
    }
    int ans = 1;
    for(int i = 1;i <= n;i++) {
        for(int j:v[i]) {
            dp[i] = max(dp[i],dp[j] + 1);
        }
        ans = max(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}