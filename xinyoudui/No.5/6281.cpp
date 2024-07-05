#include <bits/stdc++.h>
#define MAX_N 300
using namespace std;
double a[MAX_N + 5];
int main() {
    int n, xp = 1, np = 1;
    double sum = 0, p, c = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", a + i);
        if (a[xp] < a[i]) xp = i;
        if (a[np] > a[i]) np = i;
    }
    for (int i = 1; i <= n; i++) {
        if (i == xp || i == np) continue;
        sum += a[i];
    }
    p = sum / (n - 2);
    for (int i = 1; i <= n; i++) {
        if (i == xp || i == np) continue;
        c = max(c, abs(a[i] - p));
    }
    printf("%.2f %.2f\n", p, c);
    return 0;
}