#include <bits/stdc++.h>
using namespace std;
int m[5005][5005];
int main() {
    int n, r;
    scanf("%d%d", &n, &r);
    int maxx = r, maxy = r;
    for (int i = 1, x, y, w; i <= n; i++) {
        scanf("%d%d%d", &x, &y, &w);
        if (x + 1 > maxx) maxx = x + 1;
        if (y + 1 > maxy) maxy = y + 1;
        m[x + 1][y + 1] = w;
    }
    for (int i = 1; i <= maxx; i++) {
        for (int j = 1; j <= maxy; j++) {
            m[i][j] += m[i - 1][j] + m[i][j - 1] - m[i - 1][j - 1];
        }
    }
    int ans = 0;
    for (int i = 1; i <= maxx - r + 1; i++) {
        for (int j = 1; j <= maxy - r + 1; j++) {
            int k = i + r - 1, l = j + r - 1;
            int val = m[k][l] - m[i - 1][l] - m[k][j - 1] + m[i - 1][j - 1];
            if (val > ans) {
                ans = val;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}