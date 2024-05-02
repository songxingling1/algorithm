#include <bits/stdc++.h>
#define MAX_N 1000
using namespace std;
int f[MAX_N + 5],sum[MAX_N + 5];
int main() {
    int n;
    scanf("%d",&n);
    f[1] = 1;
    sum[1] = 1;
    for(int i = 2;i <= n;i++) {
        f[i] = 1 + sum[i / 2];
        sum[i] = f[i] + sum[i - 1];
    }
    printf("%d\n",f[n]);
    return 0;
}