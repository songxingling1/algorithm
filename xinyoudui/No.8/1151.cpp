#include <bits/stdc++.h>
using namespace std;
int isPrime(int x) {
    double s = sqrt(x);
    for (int i = 2; i <= s; i++) {
        if(x % i == 0) return 0;
    }
    return 1;
}
int main() {
    int x;
    cin >> x;
    for (int i = 2; i <= x / 2; i++) {
        if (isPrime(i) && isPrime(x - i)) {
            printf("%d=%d+%d", x, i, x - i);
            return 0;
        }
    }
    return 0;
}