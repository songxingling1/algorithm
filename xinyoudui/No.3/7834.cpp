#include <bits/stdc++.h>
using namespace std;
int main() {
    int k;
    long long n;
    double s = 0;
    scanf("%d", &k);
    n = 0;
    while (s < k) {
        n++;
        s += 1.0 / n;
    }
    printf("%lld\n", n);
    return 0;
}