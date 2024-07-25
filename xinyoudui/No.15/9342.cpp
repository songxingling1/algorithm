#include <bits/stdc++.h>
using namespace std;
void solve(int n) {
    int s, t;
    double mint = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &s, &t);
        if (t >= 0) mint = min(mint, t + 4500 * 3.6 / s);
    }
    printf("%d\n", (int)ceil(mint));
}
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        solve(n);
    }
    return 0;
}