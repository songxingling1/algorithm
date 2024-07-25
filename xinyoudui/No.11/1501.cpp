#include <bits/stdc++.h>
using namespace std;
void solve(int h, int u, int d, int f) {
    double pos = 0;
    double jiang = f * 0.01 * u;
    double sheng = u;
    int cnt = 1;
    while (true) {
        if (sheng > 0) {
            pos += sheng;
        }
        if (pos > h) {
            printf("SUCCESS ON DAY %d\n", cnt);
            return;
        }
        pos -= d;
        if (pos < 0) {
            printf("FAILURE ON DAY %d\n", cnt);
            return;
        }
        sheng -= jiang;
        cnt++;
    }
}
int main() {
    int h, u, d, f;
    while (scanf("%d%d%d%d", &h, &u, &d, &f) != EOF) {
        if (h == 0 && d == 0 && u == 0 && f == 0) break;
        solve(h, u, d, f);
    }
    return 0;
}