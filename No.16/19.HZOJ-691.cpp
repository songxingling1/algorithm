#include <bits/stdc++.h>
using namespace std;
int a[100005];
int n;
int main() {
    scanf("%d", &n);
    scanf("%d", a + 1);
    int ans = a[1];
    for (int i = 2; i <= n; i++) {
        scanf("%d", a + i);
        if (a[i] > a[i - 1]) {
            ans += (a[i] - a[i - 1]);
        }
    }
    printf("%d\n", ans);
    return 0;
}