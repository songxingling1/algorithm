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
    int n;
    cin >> n;
    int flag = 0;
    for (int i = 3; i <= n - 2; i++) {
        if (isPrime(i) && isPrime(i + 2)) {
            cout << i << " " << i + 2 << endl;
            flag = 1;
        }
    }
    if (!flag) cout << "empty" << endl;
    return 0;
}