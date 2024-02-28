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
        code[x] = (code[x] + code[fa[x]] + 3) % 3;
        return fa[x] = xx;
    }
    void merge (int a, int b) {
        int aa = find (a), bb = find (b);
        if (aa == bb)
            return;
        code[aa] = (2 - code[a] + code[b] + 3) % 3;
        fa[aa] = bb;
    }
    vector<int> fa, code;
};
int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    UnionSet u (n);
    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf ("%d%d%d", &a, &b, &c);
        if (a == 1) {
            u.merge (b, c);
        } else {
            if (u.find (b) != u.find (c)) {
                printf ("Unknown\n");
                continue;
            }
            switch ((u.code[b] - u.code[c] + 3) % 3) {
                case 0:
                    printf ("Tie\n");
                    break;
                case 1:
                    printf ("Loss\n");
                    break;
                case 2:
                    printf ("Win\n");
                    break;
            }
        }
    }
    return 0;
}
