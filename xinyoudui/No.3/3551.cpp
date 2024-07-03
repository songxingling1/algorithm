#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    double ans = 1;
    int m = 1, flag = -1;
    for (int i = 3; i <= 2 * n - 1; i += 2) {
        m += flag * i;
        ans += 1.0 / m;
        flag *= -1;
    }
    printf("%.3f\n", ans);
    return 0;
}