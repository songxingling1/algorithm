#include <bits/stdc++.h>
#define MAX_N 1000000
using namespace std;
int val[MAX_N + 5],dp[MAX_N + 5],len[MAX_N + 5] = {-0x3f3f3f3f};
int ind = 0;
int bs(int key) {
    int l = 0,r = ind,mid;
    while(l < r) {
        mid = (l + r + 1) / 2;
        if(len[mid] < key) l = mid;
        else r = mid - 1;
    }
    return l;
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) {
        scanf("%d",&val[i]);
    }
    for(int i = 1;i <= n;i++) {
        dp[i] = bs(val[i]) + 1;
        len[dp[i]] = val[i];
        ind = max(ind,dp[i]);
    }
    printf("%d\n",ind);
    return 0;
}