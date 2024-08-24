#include <bits/stdc++.h>
#define LC(ind) (tree[ind].lc)
#define RC(ind) (tree[ind].rc)
#define L(ind) (tree[ind].l)
#define R(ind) (tree[ind].r)
#define M(ind) (tree[ind].m)
#define S(ind) (tree[ind].sum)
#define LM(ind) (tree[ind].lm)
#define RM(ind) (tree[ind].rm)
#define defineMid int mid = (L(ind) + R(ind)) / 2

using namespace std;

struct Node {
    int lc, rc;
    int l, r;
    int m, sum, lm, rm;
} tree[1000005];
int n, m;
int a[500005];
int root, cnt = 1, t1 = 0, t2 = 1;
int flag;
void up(int a, int b, int c) {
    S(a) = S(b) + S(c);
    LM(a) = max(LM(b), S(b) + LM(c));
    RM(a) = max(RM(c), S(c) + RM(b));
    M(a) = max(M(b), M(c));
    M(a) = max(M(a), RM(b) + LM(c));
}
int buildTree(int l, int r) {
    int ind = ++cnt;
    L(ind) = l;
    R(ind) = r;
    if (l == r) {
        M(ind) = LM(ind) = RM(ind) = S(ind) = a[l];
        return ind;
    }
    defineMid;
    LC(ind) = buildTree(l, mid);
    RC(ind) = buildTree(mid + 1, r);
    up(ind, LC(ind), RC(ind));
    return ind;
}
void modify(int ind, int x, int y) {
    if (L(ind) == R(ind)) {
        M(ind) = LM(ind) = RM(ind) = S(ind) = y;
        return;
    }
    defineMid;
    if (x <= mid) modify(LC(ind), x, y);
    else modify(RC(ind), x, y);
    up(ind, LC(ind), RC(ind));
}
void query(int ind, int x, int y) {
    if (x <= L(ind) && R(ind) <= y) {
        if (flag) {
            tree[t1] = tree[ind];
            flag = 0;
        } else {
            up(t1, t2, ind);
        }
        swap(t1, t2);
        return;
    }
    defineMid;
    if (x <= mid) query(LC(ind), x, y);
    if (mid < y) query(RC(ind), x, y);
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    root = buildTree(1, n);
    for (int i = 1, x, y, k; i <= m; i++) {
        scanf("%d%d%d", &k, &x, &y);
        if (k == 1) {
            if (x > y) swap(x, y);
            flag = 1;
            query(root, x, y);
            printf("%d\n", M(t2));
        } else {
            modify(root, x, y);
        }
    }
    return 0;
}