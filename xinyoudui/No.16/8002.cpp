#include <bits/stdc++.h>
using namespace std;
int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int main() {
    int n, num1, num2, ans = 0;
    scanf("%d", &n);
    do {
        num1 = a[0] * 10000 + a[1] * 1000 + a[2] * 100 +
               a[3] * 10 + a[4];
        num2 = a[5] * 10000 + a[6] * 1000 + a[7] * 100 +
               a[8] * 10 + a[9];
        if (num1 % num2 == 0 && num1 / num2 == n) ans++;
    } while (next_permutation(a, a + 10));
    printf("%d\n", ans);
    return 0;
}