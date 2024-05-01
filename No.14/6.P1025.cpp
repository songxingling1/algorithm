#include <bits/stdc++.h>
#define MAX_N 200
#define MAX_K 6
using namespace std;
int f[MAX_N + 5][MAX_K + 5];
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= k;j++) {
            if(i < j) continue;
            if(i == j) {
                f[i][j] = 1;
                continue;
            }
            if(j == 1) {
                f[i][j] = 1;
                continue;
            }
            f[i][j] = f[i - 1][j - 1] + f[i - j][j];
        }
    }
    printf("%d\n",f[n][k]);
    return 0;
}