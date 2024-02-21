#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
class UnionSet {
public:
    UnionSet (int n) : fa (n + 1), code (n + 1, 0) {
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
        }
    }
    int get (int a, int b) {
        int aa = a, bb = b, suma = 0, sumb = 0;
        while (fa[aa] != aa) {
            suma += code[aa];
            aa = fa[aa];
        }
        while (fa[bb] != bb) {
            sumb += code[bb];
            bb = fa[bb];
        }
        if (aa != bb)
            return 3;
        return (suma - sumb + 3) % 3;
    }
    int find (int x) {          // NOLINT
        if (fa[x] == x)
            return x;
        int tmp = find (fa[x]);
        code[x] = (code[x] + code[fa[x]]) % 3;
        fa[x] = tmp;
        return tmp;
    }
    void merge (int a, int b) {
        int aa = find (a), bb = find (b);
        if (aa == bb)
            return;
        code[aa] = (1 - code[a] + code[b] + 3) % 3;
        fa[aa] = bb;
    }
    vector<int> fa, code;
};
int main () {
    int n, m, a, b, c;
    scanf ("%d%d", &n, &m);
    UnionSet u (n);
    for (int i = 0; i < m; i++) {
        scanf ("%d%d%d", &a, &b, &c);
        if (a == 1) {
            u.merge (b, c);
        } else {
            int tmp = u.get (b, c);
            switch (tmp) {
                case 0:
                    printf ("Tie\n");
                    break;
                case 1:
                    printf ("Win\n");
                    break;
                case 2:
                    printf ("Loss\n");
                    break;
                default:
                    printf ("Unknown\n");
                    break;
            }
        }
    }
    return 0;
}
