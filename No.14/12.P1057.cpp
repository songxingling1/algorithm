#include <bits/stdc++.h>
using namespace std;
int f[35][35] = {{0}};
int main() {
    int n,m,l,r;
    scanf("%d%d",&n,&m);
    f[0][1] = 1;
    for(int i = 1;i <= m;i++) {
        for(int j = 1;j <= n;j++) {
            l = j - 1;
            r = j + 1;
            if(j == 1) l = n;
            if(j == n) r = 1;
            f[i][j] = f[i - 1][l] + f[i - 1][r];
        }
    }
    printf("%d\n",f[m][1]);
    return 0;
}