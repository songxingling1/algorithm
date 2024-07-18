#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    if (n % 2 == 0) {
        n >>= 2;
        n |= 255;
        n ^= 15;
    } else {
        n <<= 2;
        n |= 15;
        n ^= 255;
    }
    printf("%d\n", n);
    return 0;
}