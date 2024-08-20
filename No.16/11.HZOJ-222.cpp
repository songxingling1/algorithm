#include <bits/stdc++.h>
using namespace std;
int a[10005];
int tree[40100];
void update(int ind) {
    tree[ind] = max(tree[ind * 2], tree[ind * 2 + 1]);
}
void build(int ind, int l, int r) {
    if (l == r) {
        tree[ind] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(ind * 2, l, mid);
    build(ind * 2 + 1, mid + 1, r);
    update(ind);
}
void modify(int ind, int l, int r, int x, int y) {
    if (l == r) {
        tree[ind] = y;
        return;
    }
    int mid = (l + r) / 2;
    if (mid >= x) {
        modify(ind * 2, l, mid, x, y);
    } else {
        modify(ind * 2 + 1, mid + 1, r, x, y);
    }
    update(ind);
}
int query(int ind, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        return tree[ind];
    }
    int mid = (l + r) / 2;
    int ans = -2147483648;
    if (x <= mid) ans = max(ans, query(ind * 2, l, mid, x, y));
    if (mid + 1 <= y) ans = max(ans, query(ind * 2 + 1, mid + 1, r, x, y));
    return ans;
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    build(1, 1, n);
    for (int i = 1, a, b, c; i <= m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        if (a == 1) {
            if (b <= c) modify(1, 1, n, b, c);
        } else {
            if (b > c) printf("-2147483648\n");
            else printf("%d\n", query(1, 1, n, b, c));
        }
    }
    return 0;
}