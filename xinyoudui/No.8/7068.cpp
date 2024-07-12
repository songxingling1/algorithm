#include <bits/stdc++.h>
using namespace std;
void F(int &x) {
    x ^= x & (x << 3);
    x ^= x & (x >> 2);
    x %= 65536;
}

void G(int &x) {
    x ^= x & (x << 2);
    x ^= x & (x >> 3);
    x %= 65536;
}
int main() {
    string s;
    int x;
    cin >> s >> x;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'F') F(x);
        else G(x);
    }
    cout << x << endl;
    return 0;
}