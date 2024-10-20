#include <bits/stdc++.h>
#define MAX_N 100005
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
int nt[MAX_N], pe[MAX_N], isd[MAX_N];
ll arr[MAX_N];
void del(int ind) {
    nt[pe[ind]] = nt[ind];
    pe[nt[ind]] = pe[ind];
    isd[ind] = 1;
}
set<pll> S;
int main() {
    int n, m, pos = 1;
    scanf("%d%d", &n, &m);
    for (int i = 1, a; i <= n; i++) {
        scanf("%d", &a);
        if (1LL * arr[pos] * a < 0) {
            arr[++pos] += a;
        } else {
            arr[pos] += a;
        }
    }
    ll cnt = 0, s = 0;
    for (int i = 1; i <= pos; i++) {
        pe[i] = i - 1;
        nt[i] = i + 1;
        S.emplace(abs(arr[i]), i);
        if (arr[i] > 0) {
            cnt++;
            s += arr[i];
        }
    }
    while (cnt > m) {
        while (isd[S.begin()->second]) S.erase(S.begin());
        int ind = S.begin()->second;
        S.erase(S.begin());
        if ((pe[ind] > 0 && nt[ind] <= pos) ||
            arr[ind] > 0) {
            s -= abs(arr[ind]);
            cnt--;
            arr[ind] += arr[pe[ind]] + arr[nt[ind]];
            S.emplace(abs(arr[ind]), ind);
            del(pe[ind]);
            del(nt[ind]);
        }
    }
    printf("%lld\n", s);
    return 0;
}