#include <bits/stdc++.h>
using namespace std;
int a[200005];
long long solve(int bit, int n) {
    vector<int> odd(n + 1);
    for (int i = 1; i <= n; i++) {
        odd[i] = (a[i] >> bit) & 1;
    }
    for (int i = 2; i <= n; i++) {
        odd[i] = odd[i] ^ odd[i - 1];
    }
    long long sum = 0;
    map<int, int> ma;
    ma[0] = 1;
    for (int i = 1; i <= n; i++) {
        sum += ma[odd[i] ^ 1];
        ma[odd[i]]++;
    }
    return sum;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    long long ans = 0;
    for (int i = 0; i < 32; i++) {
        ans += (1LL << i) * solve(i, n);
    }
    ans -= accumulate(a + 1, a + 1 + n, 0LL);
    printf("%lld\n", ans);
    return 0;
}