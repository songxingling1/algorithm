#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int x[200005],y[200005];
LL sumx[5000000],sumy[5000000];
void clac(int a[],LL sa[],int maxx,int n) {
    sort(a + 1,a + 1 + n);
    int it = 1;
    LL ps = 0,ss = 0;
    for(int i = 1;i <= n;i++) {
        ss += a[i];
    }
    for(int i = -maxx;i <= maxx;i++) {
        while(it <= n && a[it] < i) {
            ps += a[it];
            ss -= a[it++];
        }
        LL sum = 1LL * (it - 1) * i - ps + ss -  1LL * (n - it + 1) * i;
        sa[i + maxx] = sum;
    }
    sort(sa,sa + 2 * maxx + 1);
}
int main() {
    int n,d,maxx = 0;
    scanf("%d%d",&n,&d);
    for(int i = 1;i <= n;i++) {
        scanf("%d%d",&x[i],&y[i]);
        maxx = max(maxx,max(abs(x[i]),abs(y[i])));
    }
    clac(x,sumx,maxx + d,n);
    clac(y,sumy,maxx + d,n);
    LL ans = 0;
    int j = 2 * (maxx + d);
    for(int i = 0;i <= 2 * (maxx + d);i++) {
        while(j >= 0 && sumy[j] + sumx[i] > d) {
            j--;
        }
        ans += j + 1;
    }
    printf("%lld\n",ans);
    return 0;
}