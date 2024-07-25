#include <bits/stdc++.h>
using namespace std;
void solve(int n) {
    if (n == 1) {
        printf("1 ");
        return;
    }
    solve(n / 2);
    printf("%d ", n);
    solve(n - n / 2);
}
int main() {
    int n;
    scanf("%d", &n);
    solve(n);
    puts("");
    return 0;
}