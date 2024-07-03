#include <bits/stdc++.h>
using namespace std;
int main() {
    int m, b;
    scanf("%d%d", &m, &b);
    long long x = 0, y = b, ans = 0;
    do {
        ans = max(ans, (x + 1) * (y + 1) * (x + y) / 2);
        x++;
        y = floor(-x * 1.0 / m + b);
    } while (y >= 0);
    printf("%lld\n", ans);
    return 0;
}