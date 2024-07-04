#include <bits/stdc++.h>
using namespace std;
int check(int x) {
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}
int main() {
    int n, ans = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        ans++;
        while (!check(ans)) ans++;
    }
    printf("%d\n", ans);
    return 0;
}