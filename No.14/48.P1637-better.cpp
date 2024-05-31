#include <bits/stdc++.h>
#define MAX_N 100000
#define lowbit(x) ((x) & -(x))
using namespace std;
int c[2][MAX_N + 5];
int sum(int k,int a) {
    int s = 0;
    while(a > 0) {
        s += c[k][a];
        a -= lowbit(a);
    }
    return s;
}
void update(int k,int pos,int val) {
    while(pos <= MAX_N) {
        c[k][pos] += val;
        pos += lowbit(pos);
    }
}
int main() {
    int n;
    scanf("%d",&n);
    long long ans = 0;
    for(int i = 1,a;i <= n;i++) {
        scanf("%d",&a);
        ans += sum(1,a - 1);
        update(0,a,1);
        update(1,a,sum(0,a - 1));
    }
    printf("%lld\n",ans);
    return 0;
}
