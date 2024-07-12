#include <bits/stdc++.h>
using namespace std;
int main() {
    string s, maxs, mins, tmp;
    int maxl = 0, minl = 0x3f3f3f3f;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ' || s[i] == ',' || s[i] == '.') {
            if (tmp.size() == 0) continue;
            if (tmp.size() > maxl) {
                maxs = tmp;
                maxl = tmp.size();
            }
            if (tmp.size() < minl) {
                mins = tmp;
                minl = tmp.size();
            }
            tmp = "";
            if (s[i] == '.') break;
            continue;
        }
        tmp += s[i];
    }
    cout << maxs << endl << mins << endl;
    return 0;
}