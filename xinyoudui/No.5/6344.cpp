#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;
int a[MAX_N + 5];
int main() {
    int n, max_n = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        max_n = max(max_n, a[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == max_n) continue;
        ans += a[i];
    }
    printf("%d\n", ans);
    return 0;
}