#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = (s[i] - 'A' + 29) % 26 + 'a';
        } else {
            s[i] = (s[i] - 'a' + 29) % 26 + 'A';
        }
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}