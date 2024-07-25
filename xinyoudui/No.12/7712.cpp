#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
string cheng(string a, int b) {
    vector<int> ans(a.size() + 100);
    reverse(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++) {
        ans[i] = (a[i] - '0') * b;
    }
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] > 10) {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }
    }
    while (ans.size() > 1 && ans.back() == 0) ans.pop_back();
    string s;
    for (int i = ans.size() - 1; i >= 0; i--) {
        s = char(ans[i] + '0') + s;
    }
    reverse(s.begin(), s.end());
    return s;
}
string solve(int n) {
    int i = 2;
    while (n >= i) {
        arr.push_back(i);
        n -= i;
        i++;
    }
    if (n != 0) {
        arr.erase(arr.begin() + i - n - 2);
        arr.push_back(i);
    }
    string s = "1";
    for (int i = 0; i < arr.size(); i++) {
        s = cheng(s, arr[i]);
    }
    return s;
}
int main() {
    int n;
    scanf("%d", &n);
    string s = solve(n);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << s << endl;
    return 0;
}