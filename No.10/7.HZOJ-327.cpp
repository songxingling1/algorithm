#include <bits/stdc++.h>
using namespace std;
class UnionSet {
public:
    UnionSet (int n) : fa (n + 1), code (n + 1, 0) {
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
        }
    }
    int find (int x) {
        if (fa[x] == x)
            return x;
        int xx = find (fa[x]);
        code[x] = (code[x] + code[fa[x]]) % 2;
        fa[x] = xx;
        return xx;
    }
    void merge (int a, int b) {
        int aa = find (a), bb = find (b);
        if (aa == bb) {
            return;
        }
        code[aa] = (code[a] + 1 + code[b]) % 2;
        fa[aa] = bb;
    }
    vector<int> fa, code;
};
struct data {
    int a, b, c;
};
int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    UnionSet u (n);
    data d[m + 1];
    for (int i = 1; i <= m; i++) {
        scanf ("%d%d%d", &d[i].a, &d[i].b, &d[i].c);
    }
    sort (d + 1, d + m + 1,
          [] (data i, data j) -> bool { return i.c > j.c; });
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        if ((u.find (d[i].a) == u.find (d[i].b))
            && (u.code[d[i].a] + u.code[d[i].b]) % 2 == 0) {
            ans = d[i].c;
            break;
        }
        u.merge (d[i].a, d[i].b);
    }
    printf ("%d\n", ans);
    return 0;
}
