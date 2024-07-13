#include <bits/stdc++.h>
using namespace std;
int b[10005];
int d[10005];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int cnt = 0, p, ans = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", b + i);
        if (b[i] == 2) {
            d[++cnt] = i;
        }
        if (b[i] == 0) {
            p = i;
        }
    }
    cnt = 1;
    while (cnt <= m) {
        if (d[cnt] - p > 6) {
            p += 6;
        } else {
            p = d[cnt];
            cnt++;
        }
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}