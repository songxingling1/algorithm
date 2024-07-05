#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a1 = 0, a2 = 0, a3 = 0, a4 = 0;
    scanf("%d", &n);
    for (int i = 1, t; i <= n; i++) {
        scanf("%d", &t);
        if (t <= 18) a1++;
        else if (t <= 35) a2++;
        else if (t <= 60) a3++;
        else a4++;
    }
    printf("%.2f%%\n", a1 * 100.0 / n);
    printf("%.2f%%\n", a2 * 100.0 / n);
    printf("%.2f%%\n", a3 * 100.0 / n);
    printf("%.2f%%\n", a4 * 100.0 / n);
    return 0;
}