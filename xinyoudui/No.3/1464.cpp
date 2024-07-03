#include <bits/stdc++.h>
using namespace std;
int main() {
    int k, n = 1;
    scanf("%d", &k);
    double s = 1;
    while (s <= k) {
        n++;
        s += 1.0 / n;
    }
    printf("%d\n", n);
    return 0;
}