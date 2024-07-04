#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    int k = 0x3f3f3f3f;
    for (int i = 0; i * a <= n; i++) {
        if (n - (i * a + (n - i * a) / b * b) < k) {
            k = n - (i * a + (n - i * a) / b * b);
        }
    }
    printf("%d\n", k);
    return 0;
}