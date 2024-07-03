#include <bits/stdc++.h>
using namespace std;
int f(int n) {
    return n * n + 2;
}
int main() {
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += f(i);
    }
    printf("%d\n", ans);
    return 0;
}