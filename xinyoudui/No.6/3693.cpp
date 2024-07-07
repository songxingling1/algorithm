#include <bits/stdc++.h>
using namespace std;
long long sum[105];
int main() {
    int n, m;
    int maxsum = 1;
    scanf("%d%d", &n, &m);
    for (int i = 1, t; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &t);
            sum[i] += t;
        }
        if (sum[maxsum] < sum[i]) maxsum = i;
    }
    for (int i = 1; i <= n; i++) {
        printf("%lld\n", sum[i]);
    }
    printf("%d\n", maxsum);
    return 0;
}