#include <bits/stdc++.h>
using namespace std;
int main() {
    double h;
    double a;
    scanf("%lf", &h);
    a = h;
    for (int i = 1; i <= 10; i++) {
        h = h / 2.0;
        a += 2 * h;
    }
    a -= 2 * h;
    printf("%.4f\n%.7f\n", a, h);
    return 0;
}