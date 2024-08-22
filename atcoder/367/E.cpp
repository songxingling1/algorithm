#include <bits/stdc++.h>
using namespace std;
int a[200005];
int x[200005][64];
int main() {
    int n;
    long long k;
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x[i][0]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 1; i <= 60; i++) {
        for (int j = 1; j <= n; j++) {
            x[j][i] = x[x[j][i - 1]][i - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        int p = i;
        for (int j = 60; j >= 0; j--) {
            if (k >> j & 1) p = x[p][j];
        }
        printf("%d ", a[p]);
    }
    puts("");
    return 0;
}