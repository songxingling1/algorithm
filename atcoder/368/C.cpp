#include <bits/stdc++.h>
using namespace std;
int h[200005];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", h + i);
    }
    long long cnt = 0, tmp = 0;
    for (int i = 1; i <= n; i++) {
        if (tmp != 0) {
            if (h[i] == 1) {
                tmp--;
                cnt++;
                continue;
            }
            if (h[i] == 2) {
                if (tmp == 1) {
                    cnt++;
                    tmp--;
                    continue;
                } else {
                    cnt += 2;
                    tmp -= 2;
                    continue;
                }
            }
            h[i] -= tmp + 2;
            cnt += tmp;
            tmp = 0;
        }
        if (h[i] <= 0) continue;
        cnt += h[i] / 5 * 3;
        h[i] %= 5;
        if (h[i] <= 0) continue;
        if (h[i] <= 3) {
            tmp = 3 - h[i];
            cnt += h[i];
        } else {
            tmp = 0;
            cnt += 3;
        }
    }
    printf("%lld\n", cnt);
    return 0;
}