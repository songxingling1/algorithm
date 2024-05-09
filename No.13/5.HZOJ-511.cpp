#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll a,b,k;
    scanf("%lld%lld%lld",&a,&b,&k);
    ll ans = 0;
    if(k == 1) {
        printf("%lld\n",b - a);
        return 0;
    }
    if(k == 0) {
        if(b != 0) printf("%lld\n",b - a);
        else printf("%d\n",!!(a));
        return 0;
    }
    while(a != b) {
        if(a * k <= b) {
            ans += 1 + b % k;
            b /= k;
        } else {
            ans += b - a;
            break;
        }
    }
    printf("%lld\n",ans);
    return 0;
}