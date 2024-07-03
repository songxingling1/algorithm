#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, tmp;
    scanf("%d%d", &n, &m);
    while (m != 0) {
        tmp = n % m;
        n = m;
        m = tmp;
    }
    printf("%d\n", n);
    return 0;
}