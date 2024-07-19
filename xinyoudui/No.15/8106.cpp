#include <bits/stdc++.h>
using namespace std;
int a[55];
int main() {
    int n, l, r, sum = 0, cnt = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        sum += a[i];
    }
    scanf("%d%d", &l, &r);
    if (sum * 1.0 / n < l || sum * 1.0 / n > r) {
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] > r) cnt += a[i] - r;
    }
    printf("%d\n", cnt);
    return 0;
}