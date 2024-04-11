#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll a,b,k;
    scanf("%lld%lld%lld",&a,&b,&k);
    ll cnt = 0;
    if(k == 1) {
        printf("%lld",b - a);
        return 0;
    }
    if(k == 0) {
        if(b != 0) printf("%lld",b - a);
        else printf("%d",!!(a));
    }
    while(a != b) {
        if(a * k <= b) {
            cnt += 1 + b % k;
            b /= k;
        } else {
            cnt += b - a;
            break;
        }
    }
    printf("%lld\n",cnt);
    return 0;
}