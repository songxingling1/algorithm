#include <bits/stdc++.h>
using namespace std;
int main() {
    double x;
    scanf("%lf", &x);
    int ans = 0;
    while (x < 50) {
        x *= 1.1;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}