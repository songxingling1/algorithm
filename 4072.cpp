#include <bits/stdc++.h>
using namespace std;
int aa[26], bb[26], cc[26];
int main() {
    int n;
    string a, b;
    cin >> n;
    for (int k = 1; k <= n; k++) {
        cin >> a >> b;
        memset(bb, 0, sizeof(bb));
        memset(cc, 0, sizeof(cc));
        for (int i = 0; i < a.length(); i++) {
            bb[a[i] - 'a']++;
        }
        for (int i = 0; i < b.length(); i++) {
            cc[b[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            aa[i] += max(bb[i], cc[i]);
        }
    }
    for (int i = 0; i < 26; i++) {
        cout << aa[i] << endl;
    }
    return 0;
}