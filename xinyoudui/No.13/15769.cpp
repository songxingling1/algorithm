#include <bits/stdc++.h>
using namespace std;
struct ch {
    int x, y;
} a[10005];
int n, m, q;
void mapper(int v, int x, int y, int &ax, int &ay) {
    if (v == 0) {
        ax = x;
        ay = y;
        return;
    }
    if ((x == a[v].x && y >= a[v].y) || (x >= a[v].x && y == m)) {
        if (x == a[v].x && y < m) {
            return mapper(v - 1, x, y + 1, ax, ay);
        } else if (y == m && x < n) {
            return mapper(v - 1, x + 1, m, ax, ay);
        } else {
            return mapper(v - 1, a[v].x, a[v].y, ax, ay);
        }
    } else {
        return mapper(v - 1, x, y, ax, ay);
    }
}
int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= q; i++) {
        scanf("%d%d", &a[i].x, &a[i].y);
    }
    int ax, ay;
    for (int i = 1; i <= q; i++) {
        mapper(i, n, m, ax, ay);
        printf("%d\n", (ax - 1) * m + ay);
    }
    return 0;
}