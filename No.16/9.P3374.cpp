#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
using namespace std;
int a[500005];
int c[500005];
int query(int x) {
    int sum = 0;
    while (x) {
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}
void add(int pos, int x, int n) {
    a[pos] += x;
    while (pos <= n) {
        c[pos] += x;
        pos += lowbit(pos);
    }
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1, t; i <= n; i++) {
        scanf("%d", &t);
        add(i, t, n);
    }
    for (int i = 1, t, x, y; i <= m; i++) {
        scanf("%d%d%d", &t, &x, &y);
        if (t == 1) {
            add(x, y, n);
        } else {
            printf("%d\n", query(y) - query(x - 1));
        }
    }
    return 0;
}