#include <bits/stdc++.h>
using namespace std;
vector<int> x(1000005);
int n, m;
struct g {
    int u, v, w;
} a[1000005];
int check(int xx) {
    vector<int> t = x;
    for (int i = 1; i <= xx; i++) {
        t[a[i].u] -= a[i].w;
        t[a[i].v + 1] += a[i].w;
    }
    for (int i = 1, cnt = 0; i <= n; i++) {
        cnt += t[i];
        if (cnt < 0) return 0;
    }
    return 1;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1, last = 0, a; i <= n; i++) {
        scanf("%d", &a);
        x[i] = a - last;
        last = a;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &a[i].w, &a[i].u, &a[i].v);
    }
    if (check(m)) {
        printf("0\n");
        return 0;
    }
    int l = 1, r = m, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (check(mid)) l = mid + 1;
        else r = mid;
    }
    printf("-1\n%d\n", l);
    return 0;
}