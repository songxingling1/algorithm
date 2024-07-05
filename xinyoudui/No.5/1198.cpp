#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    int maxn = 0, maxm = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1, t; i <= n; i++) {
        scanf("%d", &t);
        maxn = max(maxn, t);
    }
    for (int i = 1, t; i <= m; i++) {
        scanf("%d", &t);
        maxm = max(maxm, t);
    }
    printf("%d\n", maxn + maxm);
    return 0;
}