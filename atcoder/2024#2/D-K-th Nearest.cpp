#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    sort(a + 1, a + 1 + n);
    long long b, k;
    for (int i = 1; i <= q; i++) {
        scanf("%lld%lld", &b, &k);
        if (b <= a[1]) {
            printf("%lld\n", abs(b - a[k]));
            continue;
        }
        if (b >= a[n]) {
            printf("%lld\n", abs(b - a[n + 1 - k]));
            continue;
        }
        long long l = -2e8 - 10, r = 2e8 + 10, mid;
        while (l + 1 < r) {
            mid = l + (r - l) / 2;
            int ind1 =
                lower_bound(a + 1, a + 1 + n, b - mid) - a;
            int ind2 =
                upper_bound(a + 1, a + 1 + n, b + mid) - a;
            if (ind2 - ind1 >= k) {
                r = mid;
            } else {
                l = mid;
            }
        }
        printf("%lld\n", r);
    }
    return 0;
}