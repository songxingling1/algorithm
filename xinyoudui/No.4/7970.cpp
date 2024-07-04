#include <bits/stdc++.h>
using namespace std;
int check(int x) {
    int yin = 2;
    for (int i = 2; i <= sqrt(x) && yin <= 4; i++) {
        if (x % i != 0) continue;
        if (i == x / i) yin++;
        else yin += 2;
    }
    if (yin > 4) return 0;
    else return 1;
}
int main() {
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (check(i)) ans++;
    }
    printf("%d\n", ans);
    return 0;
}