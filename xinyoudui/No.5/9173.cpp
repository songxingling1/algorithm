#include <bits/stdc++.h>
#define MAX_N 1000
using namespace std;
int t[MAX_N + 5];
int main() {
    int n, Q;
    scanf("%d%d", &n, &Q);
    for (int i = 1, l; i <= n; i++) {
        scanf("%d", &l);
        t[l]++;
    }
    int ans;
    for (int i = 1, l, r; i <= Q; i++) {
        scanf("%d%d", &l, &r);
        ans = 0;
        for (int j = l; j <= r; j++) ans += t[j];
        printf("%d\n", ans);
    }
    return 0;
}