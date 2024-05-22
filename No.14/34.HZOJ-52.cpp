#include <bits/stdc++.h>
#define MAX_N 1000000
#define S(x) ((x) * (x))
using namespace std;
long long c[MAX_N + 5],sum[MAX_N + 5];
long long dp[MAX_N + 5],f[MAX_N + 5];
int n,M;
double slope(int i,int j) {
    return 1.0 * (f[i] - f[j]) / (sum[i] - sum[j]);
}
void sets(int i,int j) {
    dp[i] = dp[j] + S(sum[i] - sum[j]) + M;
    f[i] = dp[i] + S(sum[i]);
}
int main() {
    scanf("%d%d",&n,&M);
    for(int i = 1;i <= n;i++) {
        scanf("%lld",c + i);
        sum[i] = sum[i - 1] + c[i];
    }
    deque<int> q;
    q.push_back(0);
    for(int i = 1;i <= n;i++) {
        while(q.size() >= 2 && slope(q[1],q.front()) < 2 * sum[i]) q.pop_front();
        sets(i,q.front());
        while(q.size() >= 2 && slope(i,q.back()) < slope(q.back(),q[q.size() - 2])) q.pop_back();
        q.push_back(i);
    }
    printf("%lld\n",dp[n]);
    return 0;
}