#include <bits/stdc++.h>
using namespace std;
int square[25][25];
const int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int main() {
    int n;
    scanf("%d", &n);
    int xx = 1, yy = 1, cnt = 1, statu = 0;
    square[xx][yy] = cnt;
    for (int i = 2; i <= n * n; i++) {
        xx += d[statu][0];
        yy += d[statu][1];
        square[xx][yy] = ++cnt;
        if (xx + d[statu][0] > n || xx + d[statu][0] < 1 || yy + d[statu][1] > n || yy + d[statu][1] < 1 ||
            square[xx + d[statu][0]][yy + d[statu][1]] != 0) {
            statu++;
            if (statu == 4) statu = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", square[i][j]);
        }
        puts("");
    }
    return 0;
}