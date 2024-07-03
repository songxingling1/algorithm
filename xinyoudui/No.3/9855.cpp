#include <bits/stdc++.h>
using namespace std;
int check(int x) {
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i != 0) continue;
        if (check(i) && check(n / i)) {
            printf("%d\n", n / i);
        }
    }
    return 0;
}