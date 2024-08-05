#include <bits/stdc++.h>
using namespace std;
struct man {
    int c, p;
    man(int a, int b)
    : c(a)
    , p(b) {}
    man()
    : c(0)
    , p(0) {}
};
vector<man> m;
vector<int> r;
int main() {
    int n, k;
    scanf("%d", &n);
    for (int i = 1, c, p; i <= n; i++) {
        scanf("%d%d", &c, &p);
        m.emplace_back(c, p);
    }
    scanf("%d", &k);
    for (int i = 1, tmp; i <= k; i++) {
        scanf("%d", &tmp);
        r.push_back(tmp);
    }
    sort(m.begin(),
         m.end(),
         [](const man &i, const man &j) -> bool {
             if (i.p != j.p) return i.p > j.p;
             return i.c > j.c;
         });
    sort(r.begin(), r.end());
    vector<int>::iterator it;
    int ans = 0;
    for (int i = 0; i < m.size(); i++) {
        it = lower_bound(r.begin(), r.end(), m[i].c);
        if (it != r.end()) {
            ans += m[i].p;
            r.erase(it);
        }
    }
    printf("%d\n", ans);
    return 0;
}