#include <bits/stdc++.h>
using namespace std;
string s;
struct node {
    bool isB;
    int size;
    char c;
};
int solve() {
    vector<node> sta;
    node t;
    int n = s.size();
    t.isB = false;
    t.c = ' ';
    t.size = -114514;
    sta.push_back(t);
    sta.push_back(t);
    sta.push_back(t);
    for(int i = 0;i < n;i++) {
        t.isB = false;
        t.c = s[i];
        t.size = -114514;
        sta.push_back(t);
        while(true) {
            vector<node>::reverse_iterator it = sta.rbegin();
            node a = *it;
            it++;
            node b = *it;
            it++;
            node c = *it;
            if(a.isB && b.isB) {
                t.isB = true;
                t.size = a.size + b.size;
                sta.pop_back();
                sta.pop_back();
                sta.push_back(t);
                continue;
            } else if(!(a.isB || b.isB) && ((a.c == ')' && b.c == '(') || (a.c == ']' && b.c == '[') || (a.c == '}' && b.c == '{'))) {
                t.isB = true;
                t.size = 2;
                sta.pop_back();
                sta.pop_back();
                sta.push_back(t);
                continue;
            } else if(b.isB && ((a.c == ')' && c.c == '(') || (a.c == ']' && c.c == '[') || (a.c == '}' && c.c == '{'))) {
                t.isB = true;
                t.size = 2 + b.size;
                sta.pop_back();
                sta.pop_back();
                sta.pop_back();
                sta.push_back(t);
                continue;
            }
            break;
        }
    }
    int ans = 0;
    for(int i = 0;i < sta.size();i++) {
        ans = max(ans,sta[i].size);
    }
    return ans;
}
int main() {
    cin >> s;
    printf("%d\n",solve());
    return 0;
}