#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    int base = 1;
    while (n >= base) {
        cnt++;
        n -= base;
        base *= 2;
    }
    if (n != 0) cnt++;
    printf("%d\n", cnt);
    return 0;
}