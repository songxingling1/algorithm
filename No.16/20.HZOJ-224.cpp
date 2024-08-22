#include <bits/stdc++.h>

#define LC(ind) (tree[ind].lc)
#define RC(ind) (tree[ind].rc)
#define L(ind) (tree[ind].l)
#define R(ind) (tree[ind].r)
#define SUM(ind) (tree[ind].sum)
#define X(ind) (tree[ind].x)
#define Y(ind) (tree[ind].y)
#define CNT(ind) (tree[ind].r - tree[ind].l + 1)
#define MOD(expr) ((expr) %= p)

using namespace std;
using LL = long long;

struct Node {
    int lc, rc;
    LL l, r;
    LL sum;
    LL x, y;
} tree[200005];

int a[100005];
int root, cnt = 0;
int n, m;
LL p;

void up(int ind) {
    MOD(SUM(ind) = SUM(LC(ind)) + SUM(RC(ind)));
}

void downAdd(int ind) {
    if (Y(ind) == 0) return;
    MOD(Y(LC(ind)) += Y(ind));
    MOD(Y(RC(ind)) += Y(ind));
    MOD(SUM(LC(ind)) += CNT(LC(ind)) * Y(ind));
    MOD(SUM(RC(ind)) += CNT(RC(ind)) * Y(ind));
    Y(ind) = 0;
}
void downMul(int ind) {
    if (X(ind) == 1) return;
    MOD(X(LC(ind)) *= X(ind));
    MOD(X(RC(ind)) *= X(ind));
    MOD(Y(LC(ind)) *= X(ind));
    MOD(Y(RC(ind)) *= X(ind));
    MOD(SUM(LC(ind)) *= X(ind));
    MOD(SUM(RC(ind)) *= X(ind));
    X(ind) = 1;
}
void down(int ind) {
    downMul(ind);
    downAdd(ind);
}

int buildTree(int l, int r) {
    int ind = ++cnt;
    X(ind) = 1;
    L(ind) = l;
    R(ind) = r;
    if (l == r) {
        MOD(SUM(ind) = a[l]);
        return ind;
    }
    int mid = (l + r) / 2;
    LC(ind) = buildTree(l, mid);
    RC(ind) = buildTree(mid + 1, r);
    up(ind);
    return ind;
}

LL query(int ind, int x, int y) {
    if (x <= L(ind) && R(ind) <= y) {
        return SUM(ind);
    }
    down(ind);
    int mid = (L(ind) + R(ind)) / 2;
    LL ans = 0;
    if (x <= mid) {
        MOD(ans += query(LC(ind), x, y));
    }
    if (mid < y) {
        MOD(ans += query(RC(ind), x, y));
    }
    return ans;
}

void modify(int ind, int x, int y, LL k, int type) {
    if (x <= L(ind) && R(ind) <= y) {
        if (type == 1) {
            MOD(X(ind) *= k);
            MOD(Y(ind) *= k);
            MOD(SUM(ind) *= k);
            return;
        } else {
            MOD(Y(ind) += k);
            MOD(SUM(ind) += CNT(ind) * k);
            return;
        }
    }
    down(ind);
    int mid = (L(ind) + R(ind)) / 2;
    if (x <= mid) modify(LC(ind), x, y, k, type);
    if (mid < y) modify(RC(ind), x, y, k, type);
    up(ind);
}

int main() {
    scanf("%d%d%lld", &n, &m, &p);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    root = buildTree(1, n);
    for (int i = 1, a, x, y, k; i <= m; i++) {
        scanf("%d%d%d", &a, &x, &y);
        if (a == 1 || a == 2) {
            scanf("%d", &k);
            modify(root, x, y, k, a);
        } else {
            printf("%lld\n", query(root, x, y));
        }
    }
    return 0;
}