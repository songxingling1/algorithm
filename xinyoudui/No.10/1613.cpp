#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct an {
    int s[15];
    ll f;
    ll p;
    int id;
} arr[1005];
int n, m, k;
void sets(an &x) {
    ll ans = 0;
    ll sum = 0;
    for (int i = 1; i <= k; i++) {
        ans += x.s[i] * x.s[i];
        sum += x.s[i];
    }
    double b = sum / k;
    x.p = b;
    ans = (ans - k * b * b) / k;
    x.f = ans;
}
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            scanf("%d", &arr[i].s[j]);
        }
        arr[i].id = i;
        sets(arr[i]);
    }
    sort(arr + 1, arr + 1 + n, [](const an &i, const an &j) -> bool {
        if (i.p != j.p) return i.p > j.p;
        if (i.f != j.f) return i.f < j.f;
        return i.id < j.id;
    });
    for (int i = 1; i <= m; i++) {
        printf("%d ", arr[i].id);
    }
    puts("");
    return 0;
}