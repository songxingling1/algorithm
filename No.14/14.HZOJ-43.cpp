#include <bits/stdc++.h>
#define MAX_N 1000
using namespace std;
long long f[MAX_N + 5][MAX_N + 5];
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= i;j++) {
            scanf("%lld",&f[i][j]);
        }
    }
    for(int i = n - 1;i >= 1;i--) {
        for(int j = 1;j <= i;j++) {
            f[i][j] = max(f[i + 1][j],f[i + 1][j + 1]) + f[i][j];
        }
    }
    printf("%lld\n",f[1][1]);
    return 0;
}