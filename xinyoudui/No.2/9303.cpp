#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    double ans = 0;
    ans += min(10, n) * 0.1;
    if (n > 10) {
        ans += min(n - 10, 10) * 0.075;
    }
    if (n > 20) {
        ans += min(n - 20, 20) * 0.05;
    }
    if (n > 40) {
        ans += min(n - 40, 20) * 0.03;
    }
    if (n > 60) {
        ans += min(n - 60, 40) * 0.015;
    }
    if (n > 100) {
        ans += (n - 100) * 0.01;
    }
    printf("%.2f\n", ans);
    return 0;
}