#include <bits/stdc++.h>
#define MAX_N 500000
using namespace std;
char s[MAX_N + 5];
int dp[MAX_N + 5];
vector<int> g[MAX_N + 5];
void extract(int i,int j) {
    while(s[i] == s[j]) {
        g[i].push_back(j - 1);
        i++;
        j--;
    }
}
int main() {
    scanf("%s",s + 1);
    int len = strlen(s + 1);
    for(int i = 1;i <= len;i++) {
        extract(i,i);
        extract(i,i + 1);
    }
    dp[0] = -1;
    for(int i = 1;i <= len;i++) {
        dp[i] = i - 1;
        for(int k : g[i]) {
            dp[i] = min(dp[i],dp[k] + 1);
        }
    }
    printf("%d\n",dp[len]);
    return 0;
}