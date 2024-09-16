#include <bits/stdc++.h>
using namespace std;
set<int> T[400005], L[400005];
set<int, greater<>> B[400005], R[400005];
void del(int r, int c) {
    T[r].erase(c);
    B[r].erase(c);
    L[c].erase(r);
    R[c].erase(r);
}
int main() {
    int h, w, q;
    scanf("%d%d%d", &h, &w, &q);
    int r, c, ans = h * w;
    set<int>::iterator ia, ic;
    set<int, greater<>>::iterator ib, id;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            T[i].insert(j);
            B[i].insert(j);
            L[j].insert(i);
            R[j].insert(i);
        }
    }
    while (q--) {
        scanf("%d%d", &r, &c);
        if (T[r].find(c) != T[r].end()) {
            del(r, c);
            ans--;
        } else {
            ia = T[r].upper_bound(c);
            ib = B[r].upper_bound(c);
            ic = L[c].upper_bound(r);
            id = R[c].upper_bound(r);
            if (ia != T[r].end()) {
                del(r, *ia);
                ans--;
            }
            if (ib != B[r].end()) {
                del(r, *ib);
                ans--;
            }
            if (ic != L[c].end()) {
                del(*ic, c);
                ans--;
            }
            if (id != R[c].end()) {
                del(*id, c);
                ans--;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}