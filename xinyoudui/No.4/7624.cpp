#include <bits/stdc++.h>
using namespace std;
int cnt1 = 0, cnt0 = 0;
void solve(int x) {
    while (x) {
        if (x & 1) cnt1++;
        else cnt0++;
        x >>= 1;
    }
}
int main() {
    int l, r;
    scanf("%d%d", &l, &r);
    for (int i = l; i <= r; i++) {
        solve(i);
    }
    printf("%d %d\n", cnt1, cnt0);
    return 0;
}