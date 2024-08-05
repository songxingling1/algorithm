#include <bits/stdc++.h>
using namespace std;
struct animal {
    string name;
    vector<string> arg;
} a[105];
map<string, vector<int>> m;
int n;
struct cmp {
    bool operator()(string &i, string &j) {
        return m[i].size() < m[j].size();
    }
};
priority_queue<string, vector<string>, cmp> que;
int main() {
    string t;
    scanf("%d", &n);
    for (int i = 1, k; i <= n; i++) {
        cin >> a[i].name >> k;
        for (int j = 1; j <= k; j++) {
            cin >> t;
            a[i].arg.push_back(t);
            m[t].push_back(i);
        }
    }
    for (auto i = m.begin(); i != m.end(); i++) {
        que.push(i->first);
    }
    int ans = 0;
    string tmp;
    vector<string> temp;
    while (!que.empty()) {
        tmp = que.top();
        que.pop();
        if (m[tmp].empty()) continue;
        for (int i = 0; i < m[tmp].size(); i++) {
            temp = a[m[tmp][i]].arg;
            for (int j = 0; j < temp.size(); i++) {
                m[temp[j]].erase(find(m[temp[j]].begin(),
                                      m[temp[j]].end(),
                                      m[tmp][i]));
            }
        }
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}