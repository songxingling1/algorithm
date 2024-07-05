#include <bits/stdc++.h>
using namespace std;
vector<int> a, b, c;
int main() {
    int t;
    while (scanf("%d", &t) != EOF) {
        if (t == -1) break;
        a.push_back(t);
    }
    while (scanf("%d", &t) != EOF) {
        if (t == -1) break;
        b.push_back(t);
    }
    int p1 = 0, p2 = 0;
    while (p1 < a.size() || p2 < b.size()) {
        if (p2 == b.size() || (p1 < a.size() && a[p1] >= b[p2])) {
            c.push_back(a[p1++]);
        } else {
            c.push_back(b[p2++]);
        }
    }
    for (int i : c) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}