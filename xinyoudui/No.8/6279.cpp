#include <bits/stdc++.h>
using namespace std;
double arctanx(double x) {
    double ans = 0;
    double tmp = x;
    int num = 1;
    int flag = 1;
    while (tmp / num >= 0.000001) {
        ans += tmp / num * flag;
        flag *= -1;
        num += 2;
        tmp *= x * x;
    }
    ans += tmp / num * flag;
    return ans;
}
int main() {
    double ans = 6 * arctanx(1 / sqrt(3));
    printf("%f\n",ans);
    return 0;
}