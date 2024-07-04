#include <bits/stdc++.h>
using namespace std;
int solve(int x) {
    int i = 2, ans = 0, flag = 0;
    while (x != 1) {
        if (x % i != 0) {
            if (!flag) {
                i++;
                continue;
            }
            ans++;
            i++;
            flag = 0;
            continue;
        }
        x /= i;
        flag = 1;
    }
    ans++;
    return ans;
}
int main() {
    int q, n;
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        printf("%d\n", solve(n));
    }
    return 0;
}