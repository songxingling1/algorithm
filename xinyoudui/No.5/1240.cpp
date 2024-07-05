#include <bits/stdc++.h>
#define MAX_N 1000
using namespace std;
int a[MAX_N + 5], dp1[MAX_N + 5], dp2[MAX_N + 5];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 1; i <= n; i++) {
        if (a[i - 1] <= a[i]) {
            dp1[i] = dp1[i - 1] + 1;
        } else {
            dp1[i] = 1;
        }
    }
    for (int i = n; i >= 1; i--) {
        if (a[i + 1] <= a[i]) {
            dp2[i] = dp2[i + 1] + 1;
        } else {
            dp2[i] = 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp1[i] + dp2[i] - 1);
    }
    printf("%d\n", ans);
    return 0;
}