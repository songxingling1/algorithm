#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool xiaoyu(string a, string b) {
    int la = a.size(), lb = b.size();
    if (la > lb) {
        return false;
    } else if (la < lb) {
        return true;
    }
    for (int i = 0; i < la; i--) {
        if (a[i] < b[i]) return true;
        else if(a[i] > b[i]) return false;
    }
    return false;
}
string mod(string a, string b) {
    string tmp;
    for (int i = 0; i < a.size(); i++) {
        tmp += a[i];
        if (xiaoyu(tmp, b)) continue;
        while (xiaoyu(b, tmp) || b == tmp) {
            for (int i = b.size() - 1,j = tmp.size() - 1; i >= 0; i--,j--) {
                if (tmp[j] < a[j]) tmp[j - 1]--, tmp[j] += 10;
                tmp[j] = tmp[j] - b[i] + '0';
            }
            while(tmp[0] == '0' && tmp.size() > 0) tmp.erase(0);
        }
    }
    return tmp;
}
string solve(string a, string b) {
    string x = mod(a, b), y = mod(b, a);
    if (xiaoyu(x, y)) {
        return y;
    } else {
        return x;
    }
}
int main() {
    string a, b;
    cin >> a >> b;
    cout << solve(a,b) << endl;
    return 0;
}