#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VT = vector<int>;
using VVT = vector<VT>;
using A = array<LL, 3>;
using VA = vector<A>;
using VVA = vector<VA>;
using VVVA = vector<VVA>;
class SparseTable {
private:
    using F = function<int(const int &, const int &)>;
    int n;
    VVT m;
    F fun;

public:
    void init(const VT &a, F f) {
        fun = f;
        n = a.size();
        int maxLog = 32 - __builtin_clz(n);
        m.resize(n + 1, VT(maxLog + 1));
        for (int i = 1; i < n; i++) {
            m[i][0] = a[i];
        }
        for (int j = 1; j <= maxLog; j++) {
            for (int i = 1; i <= n - (1 << (j - 1)); i++) {
                m[i][j] = fun(m[i][j - 1],
                              m[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int query(int from, int to) {
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        return fun(m[from][lg], m[to - (1 << lg) + 1][lg]);
    }
};
VVVA run;
SparseTable L;
SparseTable R;
VT l;
VT r;
int n;
void jiebao(const A &arr, LL &a, LL &b, LL &c) {
    a = arr[0];
    b = arr[1];
    c = arr[2];
}
int step(int x, int y) {
    int l = x, r = n + 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (L.query(l, mid) <= y && R.query(l, mid) >= y) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}
LL solve(int sx, int sy, int tx, int ty) {
    if (sx == tx) {
        return abs(sy - ty);
    }
    if (sx > tx) {
        swap(sx, tx);
        swap(sy, ty);
    }
    int nxt = step(sx, sy);
    if (nxt > tx) {
        return tx - sx + abs(sy - ty);
    }
    int d = (sy < l[nxt] ? 0 : 1);
    LL nnxt, dd, ccost;
    LL ret = nxt - sx + (d ? sy - r[nxt] : l[nxt] - sy);
    sx = nxt;
    for (int i = 31; i >= 0; i--) {
        jiebao(run[i][sx][d], nnxt, dd, ccost);
        if (nnxt <= tx) {
            ret += ccost;
            sx = nnxt;
            d = dd;
        }
    }
    ret +=
        tx - sx + (d ? abs(ty - r[sx]) : abs(l[sx] - ty));
    return ret;
}
int main() {
    scanf("%d", &n);
    l.resize(n + 5);
    r.resize(n + 5);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &l[i], &r[i]);
    }
    l[n + 1] = 0x3f3f3f3f;
    r[n + 1] = -0x3f3f3f3f;
    run.resize(40, VVA(n + 1, VA(2, A())));
    L.init(l, [](int i, int j) { return max(i, j); });
    R.init(r, [](int i, int j) { return min(i, j); });
    LL nxt, d, cost, nnxt, dd, ccost;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            int x = i, y = (j ? r[i] : l[i]);
            nxt = step(x, y);
            if (nxt == n + 1) {
                run[0][i][j] = {n + 1, 0, n - i + 1};
            } else if (y < l[nxt]) {
                run[0][i][j] = {
                    nxt, 0, nxt - i + l[nxt] - y};
            } else {
                run[0][i][j] = {
                    nxt, 1, nxt - i + y - r[nxt]};
            }
        }
    }
    for (int i = 1; i <= 32; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < 2; k++) {
                jiebao(run[i - 1][j][k], nxt, d, cost);
                if (nxt == n + 1) {
                    run[i][j][k] = {n + 1, 0, cost};
                } else {
                    jiebao(run[i - 1][nxt][d],
                           nnxt,
                           dd,
                           ccost);
                    run[i][j][k] = {nnxt, dd, cost + ccost};
                }
            }
        }
    }
    int q, sx, sy, tx, ty;
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
        printf("%lld\n", solve(sx, sy, tx, ty));
    }
    return 0;
}