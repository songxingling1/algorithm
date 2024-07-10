#include <bits/stdc++.h>
using namespace std;
int main() {
    double k;
    string a, b;
    cin >> k >> a >> b;
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        if(a[i] == b[i]) cnt++;
    }
    if (cnt * 1.0 / a.size() >= k) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}