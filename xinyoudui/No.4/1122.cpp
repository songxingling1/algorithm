#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    long long tmp = 1, ans = 0;
    for (int i = 1; i <= n; i++) {
        tmp *= i;
        ans += tmp;
    }
    printf("%lld\n", ans);
    return 0;
}