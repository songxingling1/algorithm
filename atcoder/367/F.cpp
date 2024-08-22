#include <bits/stdc++.h>
#define MOD 100000000000031
#define MAX_N 200005
using namespace std;
int a[MAX_N], b[MAX_N], h[MAX_N], ph1[MAX_N], ph2[MAX_N];
int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    mt19937_64 mt(time(0));
    for (int i = 1; i <= n; i++) {
        h[i] = mt();
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        ph1[i] = (h[a[i]] + ph1[i - 1]) % MOD;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", b + i);
        ph2[i] = (h[b[i]] + ph2[i - 1]) % MOD;
    }
    int l, r, L, R;
    while (q--) {
        scanf("%d%d%d%d", &l, &r, &L, &R);
        if (ph1[r] - ph1[l - 1] == ph2[R] - ph2[L - 1]) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}