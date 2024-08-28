#include <bits/stdc++.h>
using namespace std;
int a[105];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    for (int i = n - k + 1, I = 1; I <= n; I++, i++) {
        printf("%d ", a[i]);
        if (i == n) i = 0;
    }
    puts("");
    return 0;
}