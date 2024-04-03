#include <bits/stdc++.h>
#define MAX_N 100000
using namespace std;
int arr[MAX_N + 5];
double sum[MAX_N + 5] = {0};
int n,m;
bool check(double a) {
    for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + arr[i] - a;
    double minnum = 0;
    for(int i = m;i <= n;i++) {
        minnum = min(minnum,sum[i - m]);
        if(sum[i] - minnum > 0) return true;
    }
    return false;
}
double solve() {
    double l = 0,r = 0x3f3f3f3f,mid;
    while(r - l >= 0.0001) {
        mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    return r;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++) scanf("%d",&arr[i]);
    printf("%d\n",static_cast<int>(solve() * 1000));
    return 0;
}