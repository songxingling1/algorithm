#include <bits/stdc++.h>
using namespace std;
int w[25] = {0};
int f[25][20005] = {{0}};
int main() {
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i = 1;i <= m;i++) {
        scanf("%d",&w[i]);
    }
    for(int i = 1;i <= m;i++) {
        f[i][0] = 1;
        for(int j = 1;j <= n;j++) {
            f[i][j] = f[i - 1][j];
            if(j >= w[i]) f[i][j] += f[i][j - w[i]];
            f[i][j] %= 9973;
        }
    }
    printf("%d\n",f[m][n]);
    return 0;
}