#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(ll level,ll id,ll &x,ll &y) {
    if(level == 1) {
        switch(id) {
            case 1:
                x = 1;
                y = 2;
                break;
            case 2:
                x = 2;
                y = 2;
                break;
            case 3:
                x = 2;
                y = 1;
                break;
            case 4:
                x = 1;
                y = 1;
                break;
        }
        return;
    }
    ll cnt = (1LL << (2 * level)) / 4,xx,tx,ty;
    xx = (1LL << level) / 2;
    if(id <= cnt) {
        solve(level - 1,id,x,y);
        tx = x;
        ty = y;
        x = xx + 1 - ty;
        y = 2 * xx - tx + 1;
    } else if(id <= 2 * cnt) {
        solve(level - 1,id - cnt,x,y);
        x += xx;
        y += xx;
    } else if(id <= 3 * cnt) {
        solve(level - 1,id - 2 * cnt,x,y);
        x += xx;
    } else {
        solve(level - 1,id - 3 * cnt,x,y);
        tx = x;
        ty = y;
        y = tx;
        x = ty;
    }

}
int main() {
    ll t;
    scanf("%lld",&t);
    ll n,s,d;
    ll x1,y1,x2,y2;
    double ans;
    while(t--) {
        scanf("%lld%lld%lld",&n,&s,&d);
        solve(n,s,x1,y1);
        solve(n,d,x2,y2);
        ans = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        printf("%.0f\n",ans * 10);
    }
    return 0;
}