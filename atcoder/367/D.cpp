#include <bits/stdc++.h>
using namespace std;
int a[400005];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        a[i + n] = a[i];
    }
    for (int i = 1; i <= 2 * n; i++) {
        a[i] += a[i - 1];
        a[i] %= m;
    }
    long long res = 0;
    unordered_map<int, int> ma;
    for (int i = 2; i <= n; i++) {
        ma[a[i]]++;
    }
    for (int i = n + 1; i <= 2 * n; i++) {
        res += ma[a[i]];
        ma[a[i]]++;
        ma[a[i - n + 1]]--;
    }
    printf("%lld\n", res);
    return 0;
}