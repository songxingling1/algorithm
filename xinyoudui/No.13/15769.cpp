#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector<vector<int>> a;
int main() {
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    a.resize(n + 5, vector<int>(m + 5, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = (i - 1) * m + j;
        }
    }
    for (int i = 1, x, y, tmp; i <= q; i++) {
        scanf("%d%d", &x, &y);
        tmp = a[x][y];
        printf("%d\n", tmp);
        for (int j = y + 1; j <= m; j++) {
            a[x][j - 1] = a[x][j];
        }
        for (int j = x + 1; j <= n; j++) {
            a[j - 1][m] = a[j][m];
        }
        a[n][m] = tmp;
    }
    return 0;
}