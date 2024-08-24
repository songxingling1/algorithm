#include <bits/stdc++.h>
#define lowbit(x) ((x) & -(x))
using namespace std;
int n;
int ans[200005], t[200005];
int a[200005], b[200005];
void add(int pos, int x) {
    while (pos <= n) {
        t[pos] += x;
        pos += lowbit(pos);
    }
}
int query(int pos) {
    int ans = 0;
    while (pos) {
        ans += t[pos];
        pos -= lowbit(pos);
    }
    return ans;
}
int search(int x) {
    int l = 1, r = n, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (query(mid) < x) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", a + i, b + i);
        add(i, 1);
    }
    for (int i = n, tmp; i >= 1; i--) {
        tmp = search(a[i] + 1);
        ans[tmp] = b[i];
        add(tmp, -1);
    }
    for (int i = 1; i <= n; i++) {
        if (i != 1) putchar(' ');
        printf("%d", ans[i]);
    }
    puts("");
    return 0;
}