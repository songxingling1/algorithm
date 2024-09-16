#include <bits/stdc++.h>
#define MAX_N 100005
using namespace std;
struct data {
    int l, r;
    bool operator<(const data &b) const {
        return l < b.l;
    }
} s[MAX_N];
int w[MAX_N];
priority_queue<int, vector<int>, greater<>> que;
int main() {
    int t;
    int n, m;
    int ans;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &s[i].l, &s[i].r);
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d", w + i);
        }
        ans = -1;
        sort(s + 1, s + 1 + n);
        sort(w + 1, w + 1 + m);
        for (int i = 1, j = 1; i <= m; i++) {
            while (j <= n && s[j].l <= w[i]) {
                que.push(s[j++].r);
            }
            while (!que.empty() && que.top() < w[i])
                que.pop();
            if (que.empty()) {
                ans = -1;
                break;
            }
            ans = max(ans, n - (int)que.size() + 1);
            que.pop();
        }
        if (ans == -1) puts("IMPOSSIBLE!");
        else printf("%d\n", ans);
        while (!que.empty()) que.pop();
    }
    return 0;
}