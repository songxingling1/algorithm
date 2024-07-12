#include <bits/stdc++.h>
using namespace std;
int isPrime(int x) {
    for (int i = 2; i <= sqrt(x); i++) {
        if(x % i == 0) return 0;
    }
    return 1;
}
int isTurePrime(int x) {
    if(x == 1) return 0;
    int num = 0;
    int temp = x;
    while (temp) {
        num = num * 10 + temp % 10;
        temp /= 10;
    }
    return isPrime(x) && isPrime(num);
}
void printTurePrime(int a, int b) {
    int flag = 0;
    for (int i = a; i <= b; i++) {
        if (isTurePrime(i)) {
            if (flag) cout << ",";
            cout << i;
            flag = 1;
        }
    }
    if(!flag) cout << "No";
    cout << endl;
}
int main() {
    int a, b;
    cin >> a >> b;
    printTurePrime(a,b);
    return 0;
}