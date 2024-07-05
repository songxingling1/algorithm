#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, last = -1, cnt = 0, maxn = 0;
    scanf("%d", &n);
    for (int i = 1, t; i <= n; i++) {
        scanf("%d", &t);
        if (t != last) {
            maxn = max(maxn, cnt);
            cnt = 1;
            last = t;
            continue;
        }
        cnt++;
    }
    maxn = max(maxn, cnt);
    printf("%d\n", maxn);
    return 0;
}