#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    while (scanf("%d\n", &n) != EOF) {
        int maxx = 0, sum = 0;
        for (int i = 1, t; i <= n; i++) {
            scanf("%d", &t);
            maxx = max(maxx, t);
            sum += t;
        }
        if (sum - maxx <= maxx) {
            printf("%.1f\n", (sum - maxx) * 1.0);
        } else {
            printf("%.1f\n", (sum - maxx - maxx) / 2.0 + maxx);
        }
    }
    return 0;
}