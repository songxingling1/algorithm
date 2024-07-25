#include <bits/stdc++.h>
using namespace std;
void print(int n, int base) {
    if (base == 1) {
        printf("%d\n", n);
        return;
    }
    printf("%d ", n / base);
    print(n, base / 2);
}
int main() {
    int n;
    scanf("%d", &n);
    long long base = 1;
    while (base <= n) base *= 2;
    print(n, base);
    return 0;
}