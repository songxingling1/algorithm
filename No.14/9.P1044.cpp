#include <bits/stdc++.h>
#define MAX_N 18
using namespace std;
int f[MAX_N + 5];
int main() {
    int n;
    scanf("%d",&n);
    f[1] = f[0] = 1;
    for(int i = 2;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            f[i] += f[j - 1] * f[i - j];
        }
    }
    printf("%d\n",f[n]);
    return 0;
}