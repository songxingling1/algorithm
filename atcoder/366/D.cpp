#include <bits/stdc++.h>
using namespace std;
int a[105][105][105];
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            for(int k = 1;k <= n;k++) {
                scanf("%d",&a[i][j][k]);
                a[i][j][k] += a[i - 1][j][k] + a[i][j - 1][k] + a[i][j][k - 1] - a[i - 1][j - 1][k] - a[i - 1][j][k - 1] - a[i][j - 1][k - 1] + a[i - 1][j - 1][k - 1];
            }
        }
    }
    int q,lx,rx,ly,ry,lz,rz;
    scanf("%d",&q);
    while(q--) {
        scanf("%d%d%d%d%d%d",&lx,&rx,&ly,&ry,&lz,&rz);
        printf("%d\n",a[rx][ry][rz] - a[lx - 1][ry][rz] - a[rx][ly - 1][rz] - a[rx][ry][lz - 1] + a[lx - 1][ly - 1][rz] + a[lx - 1][ry][lz - 1] + a[rx][ly - 1][lz - 1] - a[lx - 1][ly - 1][lz - 1]);
    }
    return 0;
}