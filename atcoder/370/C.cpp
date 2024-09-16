#include <bits/stdc++.h>
using namespace std;
vector<string> vec;
int main() {
    string s, t;
    cin >> s >> t;
    string tmp, tt, constt;
    int n = s.size();
    for (int i = 1; i <= n; i++) {
        constt += 'z';
    }
    while (s != t) {
        tmp = constt;
        for (int i = 0; i < n; i++) {
            if (s[i] == t[i]) continue;
            tt = s;
            tt[i] = t[i];
            tmp = min(tt, tmp);
        }
        s = tmp;
        vec.push_back(tmp);
    }
    cout << vec.size() << endl;
    for (string i : vec) {
        cout << i << endl;
    }
    return 0;
}