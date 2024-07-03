#include <bits/stdc++.h>
using namespace std;
int main() {
    int flag = 1, n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += flag * i;
        flag = -1 * flag;
    }
    printf("%d\n", ans);
    return 0;
}