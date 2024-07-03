#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, a, b, tmp;
    scanf("%d%d", &n, &m);
    a = n;
    b = m;
    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    printf("%d\n", n * m / a);
    return 0;
}