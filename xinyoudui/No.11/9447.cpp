#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    string s;
    while (n) {
        s = char(n % 2 + '0') + s;
        n /= 2;
    }
    cout << s << endl;
    return 0;
}