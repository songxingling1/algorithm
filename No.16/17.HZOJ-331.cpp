#include <bits/stdc++.h>
#define lowbit(x) ((x) & -(x))
using namespace std;
int a[80005], t[80005], ans[80005];
int n;
void add(int pos, int x) {
    pos++;
    while (pos <= n + 1) {
        t[pos] += x;
        pos += lowbit(pos);
    }
}
int query(int pos) {
    pos++;
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
        if (x > query(mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}
int main() {
    scanf("%d", &n);
    a[0] = 0;
    add(1, 1);
    for (int i = 2; i <= n; i++) {
        scanf("%d", a + i);
        add(i, 1);
    }
    for (int i = n; i >= 1; i--) {
        ans[i] = search(a[i] + 1);
        add(ans[i], -1);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}