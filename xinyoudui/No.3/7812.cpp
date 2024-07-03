#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, n;
    scanf("%d%d", &x, &n);
    int ans = 0;
    if (x != 1 && x <= 5) {
        ans += (5 - x + 1) * 250;
    }
    if (x != 1) n -= 7 - x + 1;
    ans += n / 7 * 5 * 250;
    n = n % 7;
    ans += min(5, n) * 250;
    printf("%d\n", ans);
    return 0;
}