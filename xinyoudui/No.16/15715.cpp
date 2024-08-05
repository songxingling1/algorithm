#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int a[50];
struct nu {
    ll num;
    int size;
    nu(ll a, int b)
    : num(a)
    , size(b) {}
    nu()
    : num(0)
    , size(0) {}
};
ll bfs() {
    queue<nu> que;
    que.push({0, 0});
    nu t;
    while (!que.empty()) {
        t = que.front();
        que.pop();
        if (t.num != 0 && t.num % m == 0) return t.num;
        for (int i = 1; i <= n; i++) {
            if (t.size <= 16) {
                que.push({t.num * 100 + a[i], t.size + 2});
            }
        }
    }
    return -1;
}
void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    if (m == 0) {
        printf("Are you kidding me ?????\n");
        return;
    }
    sort(a + 1, a + 1 + n);
    ll num = bfs();
    if (num == -1) {
        printf("Are you kidding me ?????\n");
    } else {
        printf("%lld\n", num);
    }
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}