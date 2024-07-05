#include <bits/stdc++.h>
#define MAX_N 100000
using namespace std;
int cnt[MAX_N + 5];
int main() {
    int n, maxn = 0;
    scanf("%d", &n);
    for (int i = 1, t; i <= n; i++) {
        scanf("%d", &t);
        cnt[t]++;
        maxn = max(maxn, t);
    }
    for (int i = 0; i <= maxn; i++) {
        printf("%d\n", cnt[i]);
    }
    return 0;
}