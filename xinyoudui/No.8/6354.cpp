#include <bits/stdc++.h>
using namespace std;
int isPrime(int x) {
    double s = sqrt(x);
    for (int i = 2; i <= s; i++) {
        if(x % i == 0) return 0;
    }
    return 1;
}
int solve(int x) {
    for (int i = x / 2; i >= 2; i--) {
        if(isPrime(i) && isPrime(x - i)) return i * (x - i);
    }
    return -1;
}
int main() {
    int s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}