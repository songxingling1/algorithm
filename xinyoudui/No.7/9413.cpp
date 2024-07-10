#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    int cnt = 0;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if(s[i] >= '0' && s[i] <= '9') cnt++;
    }
    cout << cnt << endl;
    return 0;
}