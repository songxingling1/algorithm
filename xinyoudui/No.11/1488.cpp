#include <bits/stdc++.h>
using namespace std;
void chu(int &a, int &b, string s) {
    a = s[0] - '0';
    a = a * 1000 + stoi(s.substr(2, 3));
    a = a * 100000 + stoi(s.substr(6, 5));
    if (s[12] <= '9' && s[12] >= '0') {
        b = s[12] - '0';
    } else {
        b = 10;
    }
}
int main() {
    string s;
    cin >> s;
    int a, b;
    chu(a, b, s);
    int cnt = 0;
    for (int i = 9; i >= 1; i--) {
        cnt += (a % 10) * i;
        cnt %= 11;
        a /= 10;
    }
    if (cnt == b) {
        cout << "Right" << endl;
    } else {
        cout << s.substr(0, 12);
        if (cnt < 10) cout << cnt;
        else cout << "X";
        cout << endl;
    }
    return 0;
}