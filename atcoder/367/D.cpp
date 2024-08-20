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
    unordered_map<int, int> cnt;
    long long res = 0;
    for (int i = 2; i <= n; i++) cnt[a[i]]++;
    for (int i = n + 1; i <= 2 * n; i++) {
        res += cnt[a[i]];
        cnt[a[i]]++;
        cnt[a[i - n + 1]]--;
    }
    printf("%lld\n", res);
    return 0;
}