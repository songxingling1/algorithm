#include <bits/stdc++.h>
#define MAX_N 100000
using namespace std;
typedef long long ll;
int v[MAX_N + 5],a[MAX_N + 5];
int main() {
    int n,d;
    scanf("%d%d",&n,&d);
    for(int i = 1;i <= n - 1;i++) {
        scanf("%d",&v[i]);
    }
    int mi = 0x3f3f3f3f;
    long long len = 0,ans = 0;
    for(int i = 1;i < n;i++) {
        scanf("%d",&a[i]);
        len += v[i];
        mi = min(mi,a[i]);
        if(len > 0) {
            ans += (len + d - 1) / d * mi;
            len -= (len + d - 1) / d * d;
        }
    }
    printf("%lld\n",ans);
    return 0;
}