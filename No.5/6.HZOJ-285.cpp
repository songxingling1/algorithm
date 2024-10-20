#include <bits/stdc++.h>
using namespace std;
multiset<int, greater<>> s;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    s.insert(0);
    for (int i = 1, a; i <= n; i++) {
        vector<int> tmp;
        for (int i : s) {
            tmp.push_back(i);
        }
        s.clear();
        for (int i = 1; i <= m; i++) {
            scanf("%d", &a);
            for (int i : tmp) {
                if (s.size() < m || *s.begin() > i + a) {
                    s.insert(i + a);
                }
                if (s.size() > m) {
                    s.erase(s.begin());
                }
            }
        }
    }
    bool flag = false;
    for (auto it = s.rbegin(); it != s.rend(); it++) {
        if (flag) printf(" ");
        printf("%d", *it);
        flag = true;
    }
    puts("");
    return 0;
}