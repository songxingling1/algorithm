#include <bits/stdc++.h>
#define MAX_V 100000
using namespace std;
int dp[105][MAX_V + 5];
int main() {
    int V,n;
    scanf("%d%d",&V,&n);
    deque<int> q;
    for(int i = 1,v,w,s;i <= n;i++) {
        scanf("%d%d%d",&v,&w,&s);
        for(int r = 0;r < v;r++) {
            q.clear();
            for(int j = r;j <= V;j += v) {
                dp[i - 1][j] -= j / v * w;
                while(!q.empty() && dp[i - 1][q.back()] < dp[i - 1][j]) {
                    q.pop_back();
                }
                q.push_back(j);
                if((j - q.front()) / v > s) {
                    q.pop_front();
                }
                dp[i][j] = dp[i - 1][q.front()] + j / v * w; 
            }
        }
    }
    printf("%d\n",dp[n][V]);
    return 0;
}