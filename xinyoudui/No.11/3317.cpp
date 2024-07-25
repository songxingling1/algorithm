#include <bits/stdc++.h>
using namespace std;
string arr[1005];
int main() {
    string a, b;
    int pos = 0, cnt = 1;
    arr[0] = "http://www.hzxjhs.com/";
    while (cin >> a) {
        if (a == "QUIT") break;
        else if (a == "VISIT") {
            cin >> b;
            arr[++pos] = b;
            cnt = pos + 1;
            cout << b << endl;
        } else if (a == "BACK") {
            if (pos == 0) cout << "Ignored" << endl;
            else {
                pos--;
                cout << arr[pos] << endl;
            }
        } else if (a == "FORWARD") {
            if (pos == cnt - 1) cout << "Ignored" << endl;
            else {
                pos++;
                cout << arr[pos] << endl;
            }
        }
    }
    return 0;
}