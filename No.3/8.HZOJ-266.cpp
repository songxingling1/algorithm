#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
bool isOp(char c) {
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            return true;
        default:
            return false;
    }
}
int clac(int l, int r) {
    int pos = -1, num = 0x3f3f3f3f - 1, a, b = 0;
    for (int i = l; i < r; i++) {
        a = 0x3f3f3f3f;
        switch (s[i]) {
            case '(':
                b += 100;
                break;
            case ')':
                b -= 100;
                break;
            case '+':
            case '-':
                a = 1 + b;
                break;
            case '*':
            case '/':
                a = 2 + b;
                break;
            case '^':
                a = 3 + b;
                break;
        }
        if ((s[i] == '+' || s[i] == '-') &&
            (i == 0 || isOp(s[i - 1]))) {
            a += 1000;
        }
        if (num >= a) {
            num = a;
            pos = i;
        }
    }
    if (pos == -1) {
        num = 0;
        for (int i = l; i < r; i++) {
            if (s[i] < '0' || s[i] > '9') continue;
            num = num * 10 + s[i] - '0';
        }
        return num;
    } else {
        a = clac(l, pos);
        b = clac(pos + 1, r);
        switch (s[pos]) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
            case '^':
                return pow(a, b);
        }
    }
    return 0;
}
signed main() {
    cin >> s;
    cout << clac(0, s.size()) << endl;
    return 0;
}