#include <bits/stdc++.h>
using namespace std;
int main() {
    int y1, m1, d1, y2, m2, d2;
    scanf("%d%d%d%d%d%d", &y1, &m1, &d1, &y2, &m2, &d2);
    if (y2 < y1) {
        printf("-1\n");
        return 0;
    } else if (y1 == y2 && m2 < m1) {
        printf("-1\n");
        return 0;
    } else if (y1 == y2 && m1 == m2 && d2 < d1) {
        printf("-1\n");
        return 0;
    }
    int ans = y2 - y1;
    if (m2 < m1 || (m2 == m1 && d2 < d1)) {
        ans--;
    }
    printf("%d\n", ans);
    return 0;
}