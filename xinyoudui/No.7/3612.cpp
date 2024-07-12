#include <bits/stdc++.h>
using namespace std;
int nxt[1005];
int arr[1005];
int cnt = 0;
void getNext(string t) {
    int len = t.size();
    nxt[0] = -1;
    for (int i = 1; i < len; i++) {
        int j = nxt[i - 1];
        while (true) {
            if (t[i] == t[j + 1]) {
                nxt[i] = j + 1;
                break;
            }
            if (j == -1) {
                nxt[i] = -1;
                break;
            }
            j = nxt[i];
        }
    }
}
void kmp(string s, string t) {
    getNext(t);
    int tlen = t.size(), slen = s.size();
    int j = -1;
    for (int i = 0; i < slen; i++) {
        while (j != -1 && s[i] != t[j + 1]) j = nxt[j];
        if (j < tlen && s[i] == t[j + 1]) j++;
        if (j + 1 == tlen) {
            arr[++cnt] = i - tlen + 1;
            j = -1;
        }
    }
}
int main() {
    string a, b, c;
    cin >> a >> b >> c;
    arr[1] = -1;
    kmp(a, b);
    int pos = 1;
    for (int i = 0; i < a.size(); i++) {
        if (i == arr[pos]) {
            cout << c;
            pos++;
            i += b.size() - 1;
        } else {
            cout << a[i];
        }
    }
    cout << endl;
    return 0;
}