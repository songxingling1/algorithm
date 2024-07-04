#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int flag = 1, tmp = 0, num = 1;
    int a = 0, b = 1;
    double ans = 0;
    for (int i = 1, t; i <= n; i++) {
        tmp += flag * num;
        ans += b * 1.0 / (tmp);
        flag *= -1;
        num += 2;
        t = a + b;
        a = b;
        b = t;
    }
    printf("%.2f\n", ans);
    return 0;
}