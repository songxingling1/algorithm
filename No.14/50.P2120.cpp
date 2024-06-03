#include <bits/stdc++.h>
#define MAX_N 1000000
using namespace std;
typedef long long ll;
ll x[MAX_N + 5],p[MAX_N + 5],c[MAX_N + 5];
ll s[MAX_N + 5],t[MAX_N + 5],f[MAX_N + 5];
ll dp[MAX_N + 5];
void sets(int i,int j) {
    dp[i] = dp[j] + t[j] - x[i] * s[j] + x[i] * s[i] - t[i] + c[i];
    f[i] = dp[i] + t[i];
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) {
        scanf("%lld%lld%lld",x + i,p + i,c + i);
        s[i] = s[i - 1] + p[i];
        t[i] = t[i - 1] + x[i] * p[i];
    }
    deque<int> q;
    q.push_back(0);
    for(int i = 1;i <= n;i++) {
        do {
            if(q.size() < 2) break;
            ll X = s[q[1]] - s[q.front()];
            ll Y = f[q[1]] - f[q.front()];
            if(Y < x[i] * X) q.pop_front();
            else break;
        } while(1);
        sets(i,q.front());
        do {
            if(q.size() < 2) break;
            ll A = f[i] - f[q.back()];
            ll B = f[q.back()] - f[q[q.size() - 2]];
            ll C = s[i] - s[q.back()];
            ll D = s[q.back()] - s[q[q.size() - 2]];
            if(A * D < B * C) q.pop_back();
            else break;
        } while(1);
        q.push_back(i);
    }
    ll ans = dp[n];
    for(int i = n - 1;i >= 0 && s[i] == s[i + 1];i--) {
        ans = min(ans,dp[i]);
    }
    printf("%lld\n",ans);
    return 0;
}