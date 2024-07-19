#include <bits/stdc++.h>
using namespace std;
const int u[4] = {0, 5, 3, 1};
int main() {
    int a, b, c, d, e, f, x, y;
    int cnt;
    while (scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f) != EOF) {
        if (a + b + c + d + e + f == 0) {
            break;
        }
        cnt = (c + 3) / 4 + d + e + f;
        y = 5 * d + u[c % 4];
        if (b > y) {
            cnt += (b - y + 8) / 9;
        }
        x = 36 * cnt - 36 * f - 25 * e - 16 * d - 9 * c - 4 * b;
        if (a > x) {
            cnt += (x - a + 35) / 36;
        }
        printf("%d\n", cnt);
    }
    return 0;
}