#include <bits/stdc++.h>
using namespace std;
int main() {
    int h, s;
    string a;
    cin >> h >> s >> a;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 'u' && s != 0) s--;
        if (a[i] == 'd' && s != h) s++;
    }
    cout << s << endl;
    return 0;
}