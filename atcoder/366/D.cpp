#include <bits/stdc++.h>
using namespace std;
int sum[105][105][105];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                scanf("%d", &sum[i][j][k]);
                sum[i][j][k] += sum[i - 1][j][k] +
                                sum[i][j - 1][k] +
                                sum[i][j][k - 1] -
                                sum[i - 1][j - 1][k] -
                                sum[i - 1][j][k - 1] -
                                sum[i][j - 1][k - 1] +
                                sum[i - 1][j - 1][k - 1];
            }
        }
    }
    int lx, rx, ly, ry, lz, rz;
    int q;
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d%d%d%d%d", &lx, &rx, &ly, &ry, &lz, &rz);
        printf("%d\n",
               sum[rx][ry][rz] - sum[lx - 1][ry][rz] -
                   sum[rx][ly - 1][rz] -
                   sum[rx][ry][lz - 1] +
                   sum[lx - 1][ly - 1][rz] +
                   sum[lx - 1][ry][lz - 1] +
                   sum[rx][ly - 1][lz - 1] -
                   sum[lx - 1][ly - 1][lz - 1]);
    }
    return 0;
}