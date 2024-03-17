#include <bits/stdc++.h>
using namespace std;
string a, b;
vector<pair<string, string>> str;
int ans = 0x3f3f3f3f;
int deep = 1;
void dfs(string top, int step) {
    if (top == b) {
        ans = min(ans, step);
        return;
    }
    if (step == deep)
        return;
    if (step + 1 >= ans)
        return;
    string tmp;
    for (pair<string, string> i : str) {
        int pos = top.find(i.first);
        while (pos != string::npos) {
            tmp = top;
            tmp.erase(pos, i.first.size());
            tmp.insert(pos, i.second);
            pos = top.find(i.first, pos + 1);
            dfs(tmp, step + 1);
        }
    }
}
int main() {
    cin >> a >> b;
    string tmp1, tmp2;
    while (cin >> tmp1 >> tmp2) {
        str.push_back(make_pair(tmp1, tmp2));
    }
    do {
        dfs(a, 0);
        if (ans != 0x3f3f3f3f)
            break;
        deep++;
    } while (deep <= 10);
    if (ans == 0x3f3f3f3f) {
        printf("NO ANSWER!\n");
    } else {
        printf("%d\n", ans);
    }
    return 0;
}