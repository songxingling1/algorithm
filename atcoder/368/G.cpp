#include <bits/stdc++.h>
using namespace std;
using LL = long long;
struct node {
    LL sum;
    int maxx, l, r;
    node(LL a = 0, int b = 0, int c = 0, int d = 0)
    : sum(a)
    , maxx(b)
    , l(c)
    , r(d) {}
};
int a[100005], b[100005];
class xds {
private:
    vector<node> tree;
    int cnt = 0;

public:
    inline void resize(int n) {
        tree.resize(n);
    }
    int build(int l, int r) {
        int ind = ++cnt;
        if (l == r) {
            tree[ind] = node(a[l], b[l], 0, 0);
            return ind;
        }
        int mid = (l + r) / 2;
        int ll = build(l, mid);
        int rr = build(mid + 1, r);
        tree[ind] = node(tree[ll].sum + tree[rr].sum,
                         max(tree[ll].maxx, tree[rr].maxx),
                         ll,
                         rr);
        return ind;
    }
    void modify(
        int ind, int l, int r, int x, int a, int b) {
        if (l == r) {
            tree[ind].sum = a;
            tree[ind].maxx = b;
            return;
        }
        int mid = (l + r) / 2;
        int ll = tree[ind].l;
        int rr = tree[ind].r;
        if (x <= mid) modify(ll, l, mid, x, a, b);
        else modify(rr, mid + 1, r, x, a, b);
        tree[ind].sum = tree[ll].sum + tree[rr].sum;
        tree[ind].maxx = max(tree[ll].maxx, tree[rr].maxx);
    }
    node query(int ind, int l, int r, int x, int y) {
        if (x <= l && r <= y) {
            return tree[ind];
        }
        int mid = (l + r) / 2;
        node ans1, ans2;
        if (x <= mid)
            ans1 = query(tree[ind].l, l, mid, x, y);
        if (mid < y)
            ans2 = query(tree[ind].r, mid + 1, r, x, y);
        return node(ans1.sum + ans2.sum,
                    max(ans1.maxx, ans2.maxx),
                    0,
                    0);
    }
    int find(int ind, int l, int r, int x, int y) {
        if (y < l || r < x) return 0;
        if (x <= l && r <= y && tree[ind].maxx < 2)
            return 0;
        if (l == r) {
            return l;
        }
        int mid = (l + r) / 2;
        int ret = find(tree[ind].l, l, mid, x, y);
        if (ret == 0) {
            ret = find(tree[ind].r, mid + 1, r, x, y);
        }
        return ret;
    }
} t;
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", b + i);
    }
    t.resize(2 * n + 5);
    int root = t.build(1, n);
    int q;
    scanf("%d", &q);
    int x, y, op;
    while (q--) {
        scanf("%d%d%d", &op, &x, &y);
        if (op == 1) {
            a[x] = y;
            t.modify(root, 1, n, x, a[x], b[x]);
        } else if (op == 2) {
            b[x] = y;
            t.modify(root, 1, n, x, a[x], b[x]);
        } else {
            LL ans = a[x];
            x++;
            while (x <= y) {
                int pos = t.find(root, 1, n, x, y);
                if (pos == 0) {
                    ans += t.query(root, 1, n, x, y).sum;
                    break;
                } else {
                    node v =
                        t.query(root, 1, n, x, pos - 1);
                    ans += v.sum;
                    ans = max(ans + a[pos], ans * b[pos]);
                    x = pos + 1;
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}