#include <bits/stdc++.h>
using namespace std;
int solve(int n) {
    if (n == 1) return 2;
    return 2 * solve(n - 1) + 2;
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", solve(n));
    return 0;
}