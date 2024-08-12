#include <bits/stdc++.h>
using namespace std;
using A = array<int,2>;
A a[200005];
long long dp[15];
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= n;i++) {
        scanf("%d%d",&a[i][0],&a[i][1]);
    }
    sort(a + 1,a + 1 + n,[](const A &a,const A &b){
        return (b[0] - 1) * a[1] > (a[0] - 1) * b[1];
    });
    dp[0] = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = k;j >= 1;j--) {
            dp[j] = max(dp[j],a[i][0] * dp[j - 1] + a[i][1]);
        }
    }
    printf("%lld\n",dp[k]);
    return 0;
}