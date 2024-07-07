#include <bits/stdc++.h>
using namespace std;
char s[105][105];
int maxn[105];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i]);
        for (int j = 0; j < m; j++) {
            maxn[j] = max(maxn[j], s[i][j] - '0');
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] - '0' == maxn[j]) {
                ans++;
                break;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}