#include <bits/stdc++.h>
using namespace std;
int a[2005];
int b[2005];
long long tmp[2005];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    int l, r, k;
    while (m--) {
        scanf("%d%d%d", &l, &r, &k);
        for (int i = 1; i <= k; i++) {
            scanf("%d", b + i);
        }
        memset(tmp, 0, sizeof(tmp));
        tmp[0] = 1;
        for (int i = l; i <= r; i++) {
            for (int j = 1; j <= k; j++) {
                if (b[j] == a[i]) {
                    tmp[j] += tmp[j - 1];
                }
            }
        }
        printf("%lld\n", tmp[k]);
    }
    return 0;
}