#include <bits/stdc++.h>
using namespace std;
int nh[105][105];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1, t; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &t);
            if (t == 0) {
                nh[i][j] = 1;
                nh[i - 1][j] = 1;
                nh[i + 1][j] = 1;
                nh[i][j - 1] = 1;
                nh[i][j + 1] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!nh[i][j]) ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}