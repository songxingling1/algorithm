#include <bits/stdc++.h>
using namespace std;
class UnionSet {
public:
    UnionSet (int n) : fa (n + 1) {
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
        }
    }
    int find (int x) {
        return fa[x] = (fa[x] == x ? x : find (fa[x]));
    }
    void merge (int a, int b) {
        fa[find (a)] = fa[find (b)];
    }
    vector<int> fa;
};
struct data {
    int a, b, c;
};
void solve () {
    int n;
    scanf ("%d", &n);
    unordered_map<int, int> m;
    int cnt = 0;
    vector<data> d;
    d.reserve (n);
    for (int i = 0; i < n; i++) {
        scanf ("%d%d%d", &d[i].a, &d[i].b, &d[i].c);
        if (m.find (d[i].a) == m.end ()) {
            m[d[i].a] = cnt++;
        }
        if (m.find (d[i].b) == m.end ()) {
            m[d[i].b] = cnt++;
        }
    }
    UnionSet u (cnt);
    for (int i = 0; i < n; i++) {
        if (d[i].c == 1) {
            u.merge (m[d[i].a], m[d[i].b]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (d[i].c == 0
            && (u.find (m[d[i].a]) == u.find (m[d[i].b]))) {
            printf ("NO\n");
            return;
        }
    }
    printf ("YES\n");
}
int main () {
    int t;
    scanf ("%d", &t);
    while (t--)
        solve ();
    return 0;
}
