#include <bits/stdc++.h>
#define C(x) (tree[x].c)
#define L(x) (tree[x].l)
#define R(x) (tree[x].r)
using namespace std;
struct Node {
    int c, l, r;
} tree[30000005];
int n, m;
int cnt = 0, root[1000005];
int a[1000005];
int build_tree(int l, int r) {
    int ind = ++cnt;
    if (l == r) {
        C(ind) = a[l];
        return ind;
    }
    int mid = (l + r) / 2;
    L(ind) = build_tree(l, mid);
    R(ind) = build_tree(mid + 1, r);
    return ind;
}
int clone(int ind) {
    cnt++;
    tree[cnt] = tree[ind];
    return cnt;
}
int modify(int ind, int l, int r, int x, int y) {
    ind = clone(ind);
    if (l == r) {
        C(ind) = y;
        return ind;
    }
    int mid = (l + r) / 2;
    if (x <= mid) L(ind) = modify(L(ind), l, mid, x, y);
    else R(ind) = modify(R(ind), mid + 1, r, x, y);
    return ind;
}
int query(int ind, int l, int r, int x) {
    if (l == r) {
        return C(ind);
    }
    int mid = (l + r) / 2;
    if (x <= mid) return query(L(ind), l, mid, x);
    else return query(R(ind), mid + 1, r, x);
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    root[0] = build_tree(1, n);
    for (int i = 1, v, a, b, c; i <= m; i++) {
        scanf("%d%d%d", &v, &a, &b);
        if (a == 1) {
            scanf("%d", &c);
            root[i] = modify(root[v], 1, n, b, c);
        } else {
            printf("%d\n", query(root[v], 1, n, b));
            root[i] = root[v];
        }
    }
    return 0;
}