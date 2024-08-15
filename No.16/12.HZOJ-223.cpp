#include <bits/stdc++.h>
#define L(ind) (ind * 2)
#define R(ind) (ind * 2 + 1)
#define T(ind) (tree[ind].tag)
#define S(ind) (tree[ind].sum)
#define CNT(ind) (tree[ind].r - tree[ind].l + 1)
using namespace std;
struct Node {
    long long sum, tag;
    int l, r;
} tree[40005];
int n, m, root = 1;
int a[10005];
void up(int ind) {
    tree[ind].sum = tree[ind * 2].sum + tree[ind * 2 + 1].sum;
}
void build_tree(int ind, int l, int r) {
    tree[ind].l = l;
    tree[ind].r = r;
    if (l == r) {
        tree[ind].sum = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build_tree(L(ind), l, mid);
    build_tree(R(ind), mid + 1, r);
    up(ind);
}
void down(int ind) {
    if (T(ind) == 0) return;
    T(L(ind)) += T(ind);
    T(R(ind)) += T(ind);
    S(L(ind)) += CNT(L(ind)) * T(ind);
    S(R(ind)) += CNT(R(ind)) * T(ind);
    T(ind) = 0;
}
void modify(int ind, int x, int y, long long z) {
    if (x <= tree[ind].l && tree[ind].r <= y) {
        tree[ind].tag += z;
        tree[ind].sum += CNT(ind) * z;
        return;
    }
    int mid = (tree[ind].l + tree[ind].r) / 2;
    down(ind);
    if (x <= mid) modify(L(ind), x, y, z);
    if (y > mid) modify(R(ind), x, y, z);
    up(ind);
}
long long query(int ind, int x, int y) {
    if (x <= tree[ind].l && tree[ind].r <= y) {
        return S(ind);
    }
    int mid = (tree[ind].l + tree[ind].r) / 2;
    long long ans = 0;
    down(ind);
    if (x <= mid) ans += query(L(ind), x, y);
    if (y > mid) ans += query(R(ind), x, y);
    return ans;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build_tree(root, 1, n);
    for (int i = 1, a, b, c, d; i <= m; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            cin >> d;
            if (b <= c) modify(root, b, c, d);
        } else {
            if (b <= c) cout << query(root, b, c) << endl;
            else cout << 0 << endl;
        }
    }
    return 0;
}