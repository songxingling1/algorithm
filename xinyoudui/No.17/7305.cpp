#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    sort(a + 1, a + 1 + n);
    a[n + 1] = -1;
    for (int i = 1, op, x; i <= q; i++) {
        scanf("%d%d", &op, &x);
        if (op == 1) {
            printf("%d\n",
                   *lower_bound(a + 1, a + 1 + n, x));
        } else {
            printf("%d\n",
                   *upper_bound(a + 1, a + 1 + n, x));
        }
    }
    return 0;
}