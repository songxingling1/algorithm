#include <bits/stdc++.h>
using namespace std;
int sum[100005];
int main() {
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", sum + i);
        sum[i] += sum[i - 1];
    }
    scanf("%d", &m);
    for (int i = 1, l, r; i <= m; i++) {
        scanf("%d%d", &l, &r);
        printf("%d\n", sum[r] - sum[l - 1]);
    }
    return 0;
}