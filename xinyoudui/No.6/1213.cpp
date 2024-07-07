#include <bits/stdc++.h>
using namespace std;
char s[1005][1005];
int sum[1005][1005];
void solve() {
    int n, m;
    int cnt = 0;
    scanf("%d%d", &n, &m);
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '*') {
                cnt++;
                sum[i][j] = -1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '.') continue;
            for (int k = 1; k <= n; k++) {
                sum[k][j]++;
            }
            for (int k = 1; k <= m; k++) {
                sum[i][k]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (sum[i][j] == cnt) {
                printf("YES\n%d %d\n", i, j);
                return;
            }
        }
    }
    printf("NO\n");
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}