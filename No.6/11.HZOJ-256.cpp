// scope: 60

#include <bits/stdc++.h>
#define MAX_N 1000
using namespace std;
typedef long long ll;
ll gA[MAX_N + 5];
ll gB[MAX_N + 5];
ll gInd[MAX_N + 5];
int main () {
    ll n;
    scanf ("%lld", &n);
    for (ll i = 1; i <= n + 1; i++) {
        scanf ("%lld%lld", &gA[i], &gB[i]);
        gInd[i] = i;
    }
    sort (gInd + 2, gInd + 2 + n,
          [&] (ll i, ll j) -> bool {
              return gA[i] * gB[i] < gA[j] * gB[j];
          });
    ll che = gA[1], ans = 0;
    for (ll i = 2; i <= n + 1; i++) {
        if (che / gB[gInd[i]] > ans)
            ans = che / gB[gInd[i]];
        che *= gA[gInd[i]];
    }
    printf ("%lld\n", ans);
    return 0;
}