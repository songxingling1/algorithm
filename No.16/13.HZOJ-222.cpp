#include <bits/stdc++.h>
#define L(x) (tree[x].l)
#define R(x) (tree[x].r)
#define C(x) (tree[x].c)
using namespace std;
struct Node {
    int c, l, r;
} tree[20005];
int root = 1, cnt = 1;
int n, m;
int a[10005];
inline int getNewNode() {
    return ++cnt;
}
void up(int ind) {
    C(ind) = max(C(L(ind)), C(R(ind)));
}
void build_tree(int ind, int l, int r) {
    if (l == r) {
        C(ind) = a[l];
        return;
    }
    int mid = (l + r) / 2;
    L(ind) = getNewNode();
    R(ind) = getNewNode();
    build_tree(L(ind), l, mid);
    build_tree(R(ind), mid + 1, r);
    up(ind);
}
void modify(int ind, int l, int r, int x, int y) {
    if (l == r) {
        C(ind) = y;
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid) modify(L(ind), l, mid, x, y);
    else modify(R(ind), mid + 1, r, x, y);
    up(ind);
}
int query(int ind, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        return C(ind);
    }
    int mid = (l + r) / 2;
    int ans = -2147483648;
    if (x <= mid) ans = max(ans, query(L(ind), l, mid, x, y));
    if (y > mid) ans = max(ans, query(R(ind), mid + 1, r, x, y));
    return ans;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build_tree(root, 1, n);
    for (int i = 1, a, b, c; i <= m; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            if (b <= c) modify(root, 1, n, b, c);
        } else {
            if (b <= c) cout << query(root, 1, n, b, c) << endl;
            else cout << "-2147483648" << endl;
        }
    }
    return 0;
}