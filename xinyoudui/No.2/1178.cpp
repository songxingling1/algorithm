#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    if(k == 0 || k == n) {
        printf("0 0\n");
        return 0;
    }
    int ans;
    if(3LL * k <= n) {
        ans = 2 * k;
    } else {
        ans = n - k;
    }
    printf("1 %d\n",ans);
    return 0;
}