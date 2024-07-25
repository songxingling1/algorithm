#include <bits/stdc++.h>
using namespace std;
int a[100000];
int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > x) {
            cnt += a[i] - x;
            a[i] = x;
        }
        if (a[i + 1] > x) {
            cnt += a[i + 1] - x;
            a[i + 1] = x;
        }
        if (a[i] + a[i + 1] > x) {
            cnt += a[i] + a[i + 1] - x;
            a[i + 1] = x - a[i];
        }
    }
    printf("%d\n", cnt);
    return 0;
}