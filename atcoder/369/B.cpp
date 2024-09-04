#include <bits/stdc++.h>
using namespace std;
int main() {
    int flag1 = 1, flag2 = 1, ll, lr, ans = 0;
    int a, n;
    char c;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %c", &a, &c);
        if (c == 'L') {
            if (flag1) {
                ll = a;
                flag1 = 0;
            } else {
                ans += abs(a - ll);
                ll = a;
            }
        } else {
            if (flag2) {
                lr = a;
                flag2 = 0;
            } else {
                ans += abs(a - lr);
                lr = a;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}