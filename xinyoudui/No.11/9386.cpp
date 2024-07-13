#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, l, r;
    scanf("%d%d%d", &n, &l, &r);
    int cnt = 0;
    for (int i = l; i <= r; i++) {
        if (i % n == n - 1) {
            printf("%d\n", n - 1);
            return 0;
        }
        cnt = max(cnt, i % n);
    }
    printf("%d\n", cnt);
    return 0;
}