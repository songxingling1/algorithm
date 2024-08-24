#include <bits/stdc++.h>
#define LC(ind) (tree[ind].lc)
#define RC(ind) (tree[ind].rc)
#define L(ind) (tree[ind].l)
#define R(ind) (tree[ind].r)
#define M(ind) (tree[ind].m)
#define T(ind) (tree[ind].t)
#define CNT(ind) (tree[ind].r - tree[ind].l + 1)
using namespace std;
struct Node {
    int lc, rc;
    long long l, r;
    long long m, t;
} tree[200005];
int root, cnt = 0;
int a[100005];
void up(int ind) {
    M(ind) = M(LC(ind)) + M(RC(ind));
}
void down(int ind) {
    if (T(ind) == 0) {
        return;
    }
    T(LC(ind)) += T(ind);
    T(RC(ind)) += T(ind);
    M(LC(ind)) += CNT(LC(ind)) * T(ind);
    M(RC(ind)) += CNT(RC(ind)) * T(ind);
    T(ind) = 0;
}
int buildTree(int l, int r) {
    int ind = ++cnt;
    L(ind) = l;
    R(ind) = r;
    if (l == r) {
        M(ind) = a[l];
        return ind;
    }
    int mid = (l + r) / 2;
    LC(ind) = buildTree(l, mid);
    RC(ind) = buildTree(mid + 1, r);
    up(ind);
    return ind;
}
void modify(int ind, int l, int r, long long x) {
    if (l > r || r < L(ind) || R(ind) < l) return;
    if (l <= L(ind) && R(ind) <= r) {
        T(ind) += x;
        M(ind) += CNT(ind) * x;
        return;
    }
    down(ind);
    int mid = (L(ind) + R(ind)) / 2;
    if (l <= mid) modify(LC(ind), l, r, x);
    if (mid < r) modify(RC(ind), l, r, x);
    up(ind);
}
long long query(int ind, int x, int y) {
    if (x <= L(ind) && R(ind) <= y) {
        return M(ind);
    }
    down(ind);
    int mid = (L(ind) + R(ind)) / 2;
    long long ans = 0;
    if (x <= mid) ans += query(LC(ind), x, y);
    if (mid < y) ans += query(RC(ind), x, y);
    return ans;
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    for (int i = n; i >= 1; i--) {
        a[i] -= a[i - 1];
    }
    root = buildTree(1, n);
    long long l, r, q, d;
    for (int i = 1, opt; i <= m; i++) {
        scanf("%d", &opt);
        if (opt == 1) {
            scanf("%lld%lld%lld%lld", &l, &r, &q, &d);
            modify(root, l, l, q);
            modify(root, l + 1, r, d);
            modify(root, r + 1, r + 1, -q - (r - l) * d);
        } else {
            scanf("%lld", &q);
            printf("%lld\n", query(root, 1, q));
        }
    }
    return 0;
}