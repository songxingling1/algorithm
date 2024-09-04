#include <bits/stdc++.h>
using namespace std;
vector<string> c;
string target;
string ans;
int main() {
    int n;
    scanf("%d", &n);
    c.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    cin >> target;
    vector<string> st;
    for (int i = 1; i <= n; i++) {
        if (c[i] == target) {
            int len = st.size();
            for (int i = 0; i < len; i++) {
                if (i) cout << "->";
                cout << st[i];
            }
            if (len != 0) cout << "->";
            cout << target << endl;
            return 0;
        }
        if (c[i] == "return") {
            st.pop_back();
        } else {
            st.push_back(c[i]);
        }
    }
    printf("NOT REFERENCED\n");
    return 0;
}