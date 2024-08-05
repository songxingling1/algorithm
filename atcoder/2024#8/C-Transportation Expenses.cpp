#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200005];
ll check(int x, int n) {
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += min(a[i], x);
    }
    return sum;
}
int search(int l, int r, int n, ll m) {
    int mid;
    while (l < r) {
        mid = (l + r + 1) / 2;
        if (check(mid, n) > m) r = mid - 1;
        else l = mid;
    }
    return l;
}
int main() {
    int n, maxx;
    ll m, cnt = 0;
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        cnt += a[i];
        maxx = max(maxx, a[i]);
    }
    if (cnt <= m) {
        printf("infinite\n");
        return 0;
    }
    printf("%d\n", search(1, maxx, n, m));
    return 0;
}