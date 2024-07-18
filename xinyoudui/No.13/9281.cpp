#include <bits/stdc++.h>
using namespace std;
string solve(int n) {
    if (n == 2) {
        return "2";
    }
    if (n == 0) {
        return "0";
    }
    int cnt = 0, base = 1, flag = 0;
    string s;
    while (n) {
        if (n & base) {
            if (base == 2) {
                if (flag) s = '+' + s;
                s = '2' + s;
            } else {
                if (flag) s = '+' + s;
                s = "2(" + solve(cnt) + ")" + s;
            }
            flag = 1;
            n -= base;
        }
        base *= 2;
        cnt++;
    }
    return s;
}
int main() {
    int n;
    scanf("%d", &n);
    cout << solve(n) << endl;
    return 0;
}