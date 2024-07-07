#include <bits/stdc++.h>
using namespace std;
int magicSquare[505][505];
void getNextPos(int &xx, int &yy, int n) {
    int newx = xx - 1, newy = yy + 1;
    if (newx == 0) newx = n;
    if (newy == n + 1) newy = 1;
    if (magicSquare[newx][newy] == 0) {
        xx = newx;
        yy = newy;
    } else {
        newx = xx + 1;
        newy = yy;
        if (newx == 0) newx = n;
        if (newy == n + 1) newy = 1;
        xx = newx;
        yy = newy;
    }
}
void genericMagicSquare(int x) {
    int xx = 1, yy = x / 2 + 1, cnt = 1;
    magicSquare[xx][yy] = cnt;
    for (int i = 2; i <= x * x; i++) {
        getNextPos(xx, yy, x);
        magicSquare[xx][yy] = ++cnt;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    genericMagicSquare(n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", magicSquare[i][j]);
        }
        puts("");
    }
    return 0;
}