#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, T, ans = 0x3f3f3f3f;
    scanf("%d%d", &n, &T);
    for (int i = 1, c, t; i <= n; i++) {
        scanf("%d%d", &c, &t);
        if (t < T && c < ans) ans = c;
    }
    if (ans == 0x3f3f3f3f) {
        printf("TLE\n");
    } else {
        printf("%d\n", ans);
    }
    return 0;
}