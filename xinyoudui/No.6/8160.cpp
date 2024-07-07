#include <bits/stdc++.h>
using namespace std;
int square[2005][2005];
const int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int main() {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    int xx = 1, yy = 1, statu = 0;
    square[xx][yy] = 1;
    for (int i = 2; i <= n * n; i++) {
        xx += d[statu][0];
        yy += d[statu][1];
        square[xx][yy] = i;
        if (xx + d[statu][0] > n || xx + d[statu][0] < 1 || yy + d[statu][1] > n || yy + d[statu][1] < 1 ||
            square[xx + d[statu][0]][yy + d[statu][1]] != 0) {
            statu++;
            if (statu == 4) statu = 0;
        }
    }
    printf("%d\n", square[a][b]);
    return 0;
}