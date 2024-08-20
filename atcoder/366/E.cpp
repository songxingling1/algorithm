#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int x[200005], y[200005];
LL sumx[4000010], sumy[4000010];
void clac(int a[], LL sm[], int maxx, int n) {
    sort(a + 1, a + 1 + n);
    int it = 1;
    LL ps = 0, ss = 0;
    for (int i = 1; i <= n; i++) {
        ss += a[i];
    }
    for (int i = -maxx; i <= maxx; i++) {
        while (it <= n && a[it] < i) {
            ps += a[it];
            ss -= a[it];
            it++;
        }
        sm[i + maxx] = 1LL * (it - 1) * i - ps + ss -
                       1LL * (n - it + 1) * i;
    }
    sort(sm, sm + 2 * maxx + 1);
}
int main() {
    int n, d;
    scanf("%d%d", &n, &d);
    int maxx = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &x[i], &y[i]);
        maxx = max(maxx, abs(x[i]));
        maxx = max(maxx, abs(y[i]));
    };
    clac(x, sumx, maxx + d, n);
    clac(y, sumy, maxx + d, n);
    LL ans = 0;
    int j = 2 * (maxx + d);
    for (int i = 0; i <= 2 * (maxx + d); i++) {
        int l = -1, r = j, mid;
        while (l < r) {
            mid = (l + r + 1) / 2;
            if (sumx[i] + sumy[mid] > d) r = mid - 1;
            else l = mid;
        }
        ans += l + 1;
        j = l;
    }
    printf("%lld\n", ans);
    return 0;
}