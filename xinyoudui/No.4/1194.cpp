#include <bits/stdc++.h>
using namespace std;
void solve(long long x) {
    int yin = 2;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i != 0) continue;
        if (i == x / i) yin++;
        else yin += 2;
        if (yin > 3) {
            printf("NO\n");
            return;
        }
    }
    if (yin == 3) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}
int main() {
    int t;
    long long n;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &n);
        solve(n);
    }
    return 0;
}